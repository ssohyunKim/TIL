//15686. 치킨 배달
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int city[51][51];
int answer=2147000000;

vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<pair<int, int> > pick;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x){
    if(pick.size() == M){
        int dist = 0;
        for(int i = 0; i < house.size(); i ++){
            int minDist = 2147000000;
            for(int j = 0 ; j < pick.size(); j++){
                minDist = min(minDist, abs(house[i].first - pick[j].first) + abs(house[i].second - pick[j].second));
            }
            dist += minDist;
        }
        if(answer > dist){
            answer = dist;
        }
        return;
    }
    for(int i = x; i < chicken.size(); i++){
        pick.push_back(chicken[i]);
        dfs(i+1);
        pick.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> city[i][j];
            if(city[i][j] == 1){
                house.push_back(make_pair(i,j));
            }else if(city[i][j]==2){
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0);

    cout << answer << "\n";

    return 0;
}