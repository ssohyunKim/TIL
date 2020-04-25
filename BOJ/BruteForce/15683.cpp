//감시
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

struct CCTV
{
    int type, y, x;
};

int n, m, ans;
int map[8][8];
int cctv_size;
CCTV cctv[8];

const int rot_size[] = {4, 2, 4, 4, 1};

void map_copy(int desc[8][8], int src[8][8])
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            desc[y][x] = src[y][x];
        }
    }
}
// dir =>  0(오) 1(위) 2(왼) 3(아)
void update(int dir, CCTV cctv)
{
    dir = (dir % 4);

    if (dir == 0)
    {
        for (int x = cctv.x + 1; x < m; x++)
        {
            if (map[cctv.y][x] == 6)
                break;
            map[cctv.y][x] = -1;
        }
    }
    if (dir == 1)
    {
        for (int y = cctv.y - 1; y >= 0; y--)
        {
            if (map[y][cctv.x] == 6)
                break;
            map[y][cctv.x] = -1;
        }
    }
    if (dir == 2)
    {
        for (int x = cctv.x - 1; x >= 0; x--)
        {
            if (map[cctv.y][x] == 6)
                break;
            map[cctv.y][x] = -1;
        }
    }
    if (dir == 3)
    {
        for (int y = cctv.y + 1; y < n; y++)
        {
            if (map[y][cctv.x] == 6)
                break;
            map[y][cctv.x] = -1;
        }
    }
}
void dfs(int cctv_index)
{
    if (cctv_index == cctv_size)
    {   
        // 사각지대 개수 구하기
        int cnt = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (map[y][x] == 0)
                {
                    cnt++;
                }
            }
        }
        if (ans > cnt)
        {
            ans = cnt;
        }

        return;
    }
    int backup[8][8];
    int type = cctv[cctv_index].type;
    for (int dir = 0; dir < rot_size[type]; dir++)
    {
        // map 백업하기
        map_copy(backup, map);
        // map 업데이트
        if (type == 0)
        {
            update(dir, cctv[cctv_index]);
        }
        else if (type == 1)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
        }
        else if (type == 2)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
        }
        else if (type == 3)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
        }
        else if (type == 4)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
            update(dir + 3, cctv[cctv_index]);
        }
        dfs(cctv_index + 1);
        // map 원상복귀
        map_copy(map, backup);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; y++)
        {
            cin >> map[y][x];
            
            if (map[y][x] != 0 && map[y][x] != 6)
            {
                cctv[cctv_size].y = y;
                cctv[cctv_size].x = x;
                cctv[cctv_size].type = map[y][x] - 1; // 0번부터 지정하기 위해서
                cctv_size++;
            }
        }
    }

    ans = 100;
    dfs(0);

    cout << ans << "\n";
    return 0;
}