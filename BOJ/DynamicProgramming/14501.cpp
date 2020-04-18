#include <iostream>
#include <algorithm>

using namespace std;

int d[1000];
int p[1000]; // 상담했을 떄 받을 수 있는 돈
int t[1000]; // 상담 완료까지 걸리는 일 수

// i번째 날에 얻을 수 있는 최대 수익은 아래의 두 값중 큰 값
//    1. i + 1번째 날에 얻을 수 있는 최대 수익
//    2. i + Ti번째 날에 얻을 수 있는 최대 수익 + Pi
int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }
    for (int i = n; i >= 1; i--)
    {
        if (i + t[i] > n + 1)
        {
            d[i] = d[i + 1];
            continue;
        }

        d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
    }

    cout << d[1] << '\n';

    return 0;
}ß