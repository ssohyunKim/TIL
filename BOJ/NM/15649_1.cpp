#include <iostream>

#define MAX 9
using namespace std;

int n, m;
int num[MAX];
int pick[MAX];
bool visited[MAX];

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
        if (!visited[i])
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
        num[i] = i + 1;
    }

    dfs(0);

    return 0;
}
