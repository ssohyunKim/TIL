#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

char map[13][7];
bool visit[13][7];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int cnt = 0;

void dfs(int x, int y, char color)
{
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
            continue;
        if (!visit[nx][ny] && map[nx][ny] == color)
        {
            cnt++;
            dfs(nx, ny, color);
        }
    }
}

void bomb(int x, int y, char color)
{
    map[x][y] = '.'; // 갱신

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
            continue;
        if (map[nx][ny] == color)
        {
            bomb(nx, ny, color);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> map[i][j];
        }
    }

    while (1)
    {
        int change = 0;
        memset(visit, false, sizeof(visit)); // 초기화

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cnt = 0; //터질 수 있는 다른 뿌요도 체크하기 위해 0으로 초기화

                if (!visit[i][j] && map[i][j] != '.')
                {
                    cnt++;
                    dfs(i, j, map[i][j]);

                    if (cnt >= 4) //뿌요가 4개 이상이면
                    {
                        change++; // 변화가 있으면 증가
                        bomb(i, j, map[i][j]); //터트리기
                    }
                }
            }
        }

        // 블록 내리기 column:열  row:행
        for (int column = 0; column < 6; column++)
        {
            for (int row = 11; row >= 0; row--)
            {
                if (map[row][column] == '.')
                {
                    int new_row = row - 1;
                    while (new_row >= 0 && map[new_row][column] == '.')
                    {
                        // 행 값은 0 이상이고 '.' 일 때만 진행(뿌요를 만나면 탈출)
                        --new_row;
                    }

                    if (new_row <= 0)
                        new_row = 0; // 음수가 나올 수 있으므로

                    swap(map[new_row][column], map[row][column]); // 블록 내리기(위치 교환)
                }
            }
        }

        if (change == 0)
            break; // change가 0이라는 것은 갱신된 뿌요가 없다는 뜻이므로 빠져나온다.
        ++ans;
    }

    cout << ans << "\n";

    return 0;
}
