#include <iostream>
#include <vector>

using namespace std;

int r, c, t;

int map[2][50][50];

int ux, uy, dx, dy;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void spread(int cur)
{
    int next = (cur + 1) % 2;
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
        {
            if (map[cur][y][x] == -1)
            {
                map[next][y][x] = -1;
            }
            else
            {
                map[next][y][x] = 0;
            }
        }
    }

    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
        {
            int val = map[cur][y][x] / 5; // 확산된 미세먼지의 양
            int cnt = 0;                  // 실제로 확산된 미세먼지의 양
            for (int dir = 0; dir < 4; dir++)
            {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny < 0 || ny >= -r || nx < 0 || nx >= c)
                    continue;
                if (map[cur][y][x] != -1)
                {
                    map[next][y][x] += val;
                    cnt += val;
                }
            }
            if (map[next][y][x] != -1)
            {
                map[next][y][x] += (map[cur][y][x] - val);
            }
        }
    }
}
void move(int cur)
{
    //상단부분
    for(int y = uy-1; y > 0 ; y--){
        map[cur][y][0] = map[cur][y-1][0]; //위쪽의 미세먼지를 아래쪽으로
    }

    for(int x = 0; x < c-1; x++){
        map[cur][0][x] = map[cur][0][x+1]; //오른쪽의 미세먼지를 왼쪽으로
    }
    
    for(int y = 0; y < uy; y++){
        map[cur][y][c-1] = map[cur][y+1][c-1]; //아래의 미세먼지를 위로
    }

    for(int x = c-1; x > 0; x--){
        map[cur][uy][x] = map[cur][uy][x-1]; //왼쪽의 미세먼지를 오른쪽으로
    }

    map[cur][uy][1] = 0; //깨끗한 바람

    //하단부분
    for(int y = dy+1; y < r ; y++){
        map[cur][y][0] = map[cur][y+1][0]; //위쪽의 미세먼지를 아래쪽으로
    }

    for(int x = 0; x < c-1; x++){
        map[cur][r-1][x] = map[cur][r-1][x+1];
    }

    for(int y = r-1; y< dy; y--){
        map[cur][y][c-1] = map[cur][y-1][c-1];
    }

    for(int x = c-1; x > 1; x--){
        map[cur][dy][x] = map[cur][dy][x-1];
    }

    map[cur][dy][1] = 0; //깨끗한 바람

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    uy = -1; // 공기청정기 초기화
    cin >> r >> c >> t;

    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
        {
            cin >> map[0][y][x];
            if (map[0][y][x] == -1)
            {
                if (uy == -1)
                {
                    uy = y;
                    ux = x;
                }
                else
                {
                    dy = y;
                    dx = x;
                }
            }
        }
    }

    int cur = 0;
    for (int i = 0; i < t; i++)
    {
        spread(cur);
        cur = (cur + 1) % 2; // 0이면 1, 1이면 0으로 왔다갔다
        move(cur);
    }

    int cnt = 0;
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
        {
            if (map[cur][y][x] != -1)
            {
                cnt += map[cur][y][x];
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}