#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans;
int map[51][51];
vector<pair<int, int> > house;
vector<pair<int, int> > shop;
vector<pair<int, int> > pick;

void dfs(int x){
    if(pick.size() == m){
        // 도시의 치킨 거리의 최솟값 구하기
        int val = 0;
        for(int i = 0; i < house.size(); i ++){
            int minDist = 999999;
            for(int j = 0 ; j < pick.size(); j++){
                minDist = min(minDist, 
                abs(house[i].first - pick[j].first) + abs(house[i].second - pick[j].second));
            }
            val += minDist;
        }
        if(ans > val){
            ans = val;
        }
        return;
    }
    for(int i = x; i < shop.size(); i++){
        pick.push_back(shop[i]);
        dfs(i+1);
        pick.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            // 집 위치 좌표값 넣어주기
            if(map[i][j] == 1){
                house.push_back(make_pair(i, j));
            // 치킨집 좌표값 넣어주기
            }else if(map[i][j] == 2){
                shop.push_back(make_pair(i, j));
            }
        }
    }

    ans = 99999999;
    
    dfs(0);

    cout << ans << "\n";

    return 0;
}
