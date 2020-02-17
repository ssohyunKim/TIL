#include <iostream>

using namespace std;
int m[101]; //동전 배열
int dp[10001]; // dp[x] : x원을 만들 수 있는 경우의 수 
int n, k;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k; //n:동전의 종류, k:가치의 합
    
    for(int i=0; i<n; i++){
        cin >> m[i];
    }
    
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j - m[i] >= 0){
                dp[j] += dp [j-m[i]];
            }
        }
    }
    cout << dp[k] << "\n";
}

