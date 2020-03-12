#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[301]; //계단 점수
int dp[301]; //각 계단까지의 최대값
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n; //계단의 개수
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    dp[1] = max(arr[0]+arr[1], arr[1]);
    dp[2] = max(arr[0]+arr[2], arr[1]+arr[2]);
    
    for(int i=3; i<n; i++){
        dp[i] = max(arr[i]+dp[i-2], arr[i-1]+arr[i]+dp[i-3]);
    }
    cout << dp[n-1] << "\n";
    
    return 0;
}
