//1932. 정수 삼각형
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[501][501];
int arr[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0; 

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            int k = j-1;
            if(k<0) k=0;
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][k]);
        }
    }

    for(int i=0; i<n; i++){
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans <<"\n";

    return 0;
}