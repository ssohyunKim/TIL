//12865.평범한 배낭
#include <iostream>
#include <vector>

using namespace std;

int ans[100][100001]; // n개의 물건으로 k무게를 만들 때의 무게
vector<pair<int,int> > profit;
int N, K;
int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        int w, v;
        cin >> w >> v;
        profit.push_back(make_parir(w, v));
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=K; j++){
            if(i==0){//물건을 아무것도 선택하지 않았을때
                if(profit[i].first <= j){
                    ans[i][j] = profit[i].second;
                }
                continue;
            }
            //넣으려는 물건이 무게조건을 충족했을때
            //이전물건의 가치와 이전물건에 현재 물건을 넣었을때의 가치 중에서 큰 값을 선택
            if(profit[i].first <= j){
                ans[i][j] = max(ans[i-1][j], ans[i-1][j-profit[i].first] + profit[i].second);
            }else{ //무게조건을 충족하지 못하면 이전 물건의 가치
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    cout << ans[i-1][k] << "\n";

    return 0;
}