#include <iostream>
#include <algorithm>

#define MAX 8
using namespace std;

int n, m;
int num[MAX];
int pick[MAX];

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
        pick[cnt] = num[i];
        dfs(cnt + 1);
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