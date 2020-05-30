#include <iostream>
#include <cstring>

using namespace std;

long long dp[5001]; //문자열 길이가 i 일때 개수
long long mod = 1000000007LL;

//중간값 k를 기준으로 좌측과 우측을 나누고, 0이 될때까지 재귀호출을 이용해 나눠준다.
long long go(int L) {
    if (L == 0) return 1; // 빈 문자열
    else if (dp[L] >= 0) return dp[L]; // 0개도 처리하기 위함
    dp[L] = 0;
    for (int i = 2; i <= L; i+= 2) {
        dp[L] += (go(i - 2) * go(L - i));
        dp[L] %= mod;
    }
    return dp[L];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int t; 
    cin >> t;
    while (t--) {
        int L; 
        cin >> L;
        if (L % 2 == 1) { //홀수일 때?
            cout << 0 << "\n";
        }
        else {
            cout << go(L) <<"\n";
        }
    }
    return 0;
}