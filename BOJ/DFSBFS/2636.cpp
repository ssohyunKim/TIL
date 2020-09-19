//2636. 치즈
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int v[101][101] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int out[101][101] = {0};
int flag = 1;

int N, M;

void dfs(int x, int y)
{
    if (out[x][y] == 0)
    {
        out[x][y] = 1;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (v[nx][ny] == 0 && out[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
    }
    return;
}

int main(void)
{
    int prev_num = 0;
    int cnt = 0;
    int answer = 0;
    int num = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
            if (v[i][j])
                num++;
        }

    while (flag)
    {
        if (num)
            prev_num = num;
        flag = 0;
        memset(out, 0, sizeof(out));
        dfs(0, 0);

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (out[nx][ny] == 1)
                        cnt++;
                }
                if (v[i][j] == 1 && cnt >= 1)
                {
                    v[i][j] = 0;
                    flag = 1;
                    num--;
                }
                cnt = 0;
            }
        }
        answer++;
    }

    cout << answer - 1  << "\n" << prev_num;

    return 0;
}
