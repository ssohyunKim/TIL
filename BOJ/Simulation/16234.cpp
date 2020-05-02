#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct nation
{
    int x, y;
};

int n, l, r, cnt, ans;
int map[50][50];
bool check[50][50], moving[50][50];
const int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int dfs(int y, int x)
{
    check[y][x] = true;
    int population = map[y][x];
    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        int diff = abs(map[y][x] - map[ny][nx]);

        if (diff < l || diff > r || check[ny][nx])
            continue;

        moving[ny][nx] = true;
        cnt++;
        population += dfs(ny, nx);
    }
    return population;
}

void migrate(int p)
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (moving[y][x])
            {
                map[y][x] = p;
                moving[y][x] = false;
            }
        }
    }
}

void solve()
{
    int ans = 0;
    while (true)
    {
        bool moved = false;
        memset(check, false, sizeof(check));
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (!check[y][x])
                {
                    cnt = 1;
                    int population = dfs(y, x) / cnt;
                    if (cnt > 1)
                    {
                        map[y][x] = population;
                        migrate(population);
                        moved = true;
                    }
                }
            }
        }
        if (moved)
            ans++;
        else
            break;
    }
    printf("%d\n", ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> r;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%d", &map[y][x]);
        }
    }
    solve();
    return 0;
}