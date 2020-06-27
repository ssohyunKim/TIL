#include <string>
#include <vector>

using namespace std;

long long dp[20001];
long long solution(int n) {
    long long answer = 0;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    if(n==1){
        answer = 1;
    }else if(n==2){
        answer = 2;
    }else{
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2])% 1234567;
        }
        answer = dp[n];
    }
    return answer;
}