//2294. 동전 2
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    // -1로 초기화 해줘서 불가능한 경우 처리
    for (int i = 1; i <= k; i++)
    {
        dp[i] = -1;
    }

    sort(coin, coin + n);

    //dp[i]는 만들 수 있는 최소 동전의 개수
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //i원 에서 j번 동전을 쓸 수 있는 지 체크 
            if (i - coin[j] >= 0 && dp[i - coin[j]] != -1)
            {
                if (dp[i] == -1 || dp[i] > dp[i - coin[j]] + 1)
                {
                    dp[i] = dp[i - coin[j]] + 1;
                }
            }
        }
    }

    cout << dp[k] << "\n";

    return 0;
}