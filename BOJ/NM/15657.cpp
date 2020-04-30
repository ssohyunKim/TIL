#include <iostream>
#include <algorithm>

#define MAX 9
using namespace std;

int n, m;
int num[MAX];
int pick[MAX];

// N개의 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
// 고른 수열은 비내림차순이어야 한다.

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << pick[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (num[i] >= pick[cnt - 1])
        {
            pick[cnt] = num[i];
            dfs(cnt + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num, num + n);
    dfs(0);

    return 0;
}