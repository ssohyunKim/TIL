#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
 
int dp[501][501];
int cost[501];
int sum[501];
int t, k, i;
 
int main() {
    cin >> t;
    while (t--) {
        cin >> k;
        for (i = 1; i <= k; ++i) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
 
        for (int d = 1; d < k; ++d) {
            for (int tx = 1; tx + d <= k; tx++) {
                int ty = tx + d;
                dp[tx][ty] = 2147000000;//2147483647
 
                for (int mid = tx; mid < ty; ++mid)
                    dp[tx][ty] =
                        min(dp[tx][ty], 
                            dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
            }
        }
 
        cout << dp[1][k] << "\n";
    }
    return 0;
}