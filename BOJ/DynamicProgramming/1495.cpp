#include <iostream>

using namespace std;

int n, s, m;
int v[101];
bool dp[101][1001];
// P+V[i], P-V[i]
// 1. 0보다 작은 값이나,
// 2. M보다 큰 값으로 볼륨 바꿀 수 없음.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s >> m;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    dp[0][s] = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            if(!dp[i][j]){
                continue;
            }
            if(j-v[i]>=0){
                dp[i+1][j-v[i]] = true;
            }
            if(j+v[i]<=m){
                dp[i+1][j+v[i]] = true;
            }
        }
    }
    
    int k;
    for(k=m; k>=0; k--){
        if(dp[n][k]){
            break;
        }
    }

    cout << k << "\n";

    return 0;
}