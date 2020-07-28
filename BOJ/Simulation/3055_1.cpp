// 3055. 탈출
#include <iostream>
#include <queue>

using namespace std;

char map[51][51]; // 지도
int R, C;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int, int>> w;
queue<pair<int, int>> q;

void water()
{
    while(!w.empty())
    {
        int x = w.front().first;
        int y = w.front().second;
        w.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (map[nx][ny] == '.')
            {
                map[nx][ny] = '*';
                w.push(make_pair(nx, ny));
            }
        }
    }
}
bool move()
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (map[nx][ny] == 'D')
            {
                return true;
            }
            if (map[nx][ny] == '.')
            {
                map[nx][ny] = 'S';
                q.push(make_pair(nx, ny));
            }
        }
    }
    return false;
}
int main()
{
    int time = 0;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];

            //고슴도치인경우
            if (map[i][j] == 'S')
            {
                q.push(make_pair(i, j));
                //물인경우
            }
            else if (map[i][j] == '*')
            {
                w.push(make_pair(i, j));
            }
        }
    }

    while (true)
    {
        time++;

        if (q.size() == 0)
        {
            cout << "KAKTUS\n";
            return 0;
        }
        water();
        if (move())
        {
            cout << time << "\n";
            return 0;
        }
    }
}