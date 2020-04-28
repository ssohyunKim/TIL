#include <iostream>
#include <algorithm>

#define MAX 9
using namespace std;

// N개의 자연수 중에서 M개를 고른 수열
// 고른 수열은 오름차순이어야 한다.

int num[MAX];
int pick[MAX];
bool visited[MAX];
int n, m;

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
        if (!visited[i] && num[i] >= pick[cnt-1])
        {
            visited[i] = true;
            pick[cnt] = num[i];
            dfs(cnt + 1);
            visited[i] = false;
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
