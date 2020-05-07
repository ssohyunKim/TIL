#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char map[12][6];
bool visited[12][6];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int>> q;

// 1. dfs로 뿌요의 위치를 큐에 넣어준다.
// 2. 큐의 사이즈가 4이상이면 bomb, 아니면 큐를 비운다.
// 3. 중력으로 내려준다.

void dfs(int y, int x, char color)
{

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6)
            continue;
        if (map[ny][nx] == color && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            q.push(make_pair(ny, nx));
            dfs(ny, nx, map[ny][nx]);
        }
    }
}
void bomb()
{
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        map[y][x] = '.';
    }
}
void reset()
{
    while (!q.empty())
    {
        q.pop();
    }
}
void gravity()
{
    for (int row = 11; row >= 0; row--)
    {
        for (int col = 0; col < 6; col++)
        {
            if (map[row][col] == '.')
                continue;
            int ny = row;
            char mark = map[row][col];
            map[row][col] = '.';
            while (true)
            {
                if (ny + 1 < 0 || col < 0 || ny + 1 >= 12 || col >= 6)
                    break;
                if (map[ny + 1][col] != '.')
                    break;
                ny++;
            }
            map[ny][col] = mark;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int combo = 0;

    for (int y = 0; y < 12; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            cin >> map[y][x];
        }
    }

    while (true)
    {
        bool flag = false;
        memset(visited, false, sizeof(visited));
        for (int y = 0; y < 12; y++)
        {
            for (int x = 0; x < 6; x++)
            {
                if (!visited[y][x] && map[y][x] != '.')
                {
                    dfs(y, x, map[y][x]);
                    if (q.size() >= 4)
                    {
                        flag = true;
                        bomb();
                    }
                    reset();
                }
            }
        }
        if (!flag)
            break;
        else
        {
            combo++;
            gravity();
        }
    }

    cout << combo << "\n";

    return 0;
}