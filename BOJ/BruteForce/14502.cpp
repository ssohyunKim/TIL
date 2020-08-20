//14502. 연구소
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[9][9];
int answer = -2147000000;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void spread()
{
    queue<pair<int, int> > q;
    int copy_map[9][9];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            copy_map[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copy_map[i][j] == 2)
            {
                //바이러스의 위치를 큐에 넣는다.
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (copy_map[nx][ny] == 0)
            {
                copy_map[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }

    //안전구역 개수 세기
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copy_map[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    answer = max(cnt, answer);
}
void dfs(int cnt)
{
    if (cnt == 3)
    {
        //바이러스 퍼트리기
        spread();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                dfs(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //N:세로, M:가로
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << answer << "\n";

    return 0;
}