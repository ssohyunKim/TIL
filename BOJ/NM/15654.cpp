#include <iostream>
#include <algorithm>

#define MAX 9
using namespace std;

int n, m;
int num[MAX];
int pick[MAX];
bool visited[MAX];

// N개의 자연수 중에서 M개를 고른 수열
// 중복되는 수열을 여러 번 출력하면 안되며
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

void dfs(int idx, int cnt)
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
        if (!visited[i])
        {
            visited[i] = true;
            pick[cnt] = num[i];
            dfs(idx + 1, cnt + 1);
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
    dfs(0, 0);

    return 0;
}