#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, x, y, d, g, result;
int ex, ey; //끝점의 좌표
bool map[101][101];

//오, 위, 왼, 아
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<int> dragon; //이전 세대의 방향정보를 저장하는 배열

//1.
void curve(vector<int> &dragon)
{
    int size = (int)dragon.size();

    for (int i = size - 1; i >= 0; i--)
    {
        int dir = (dragon[i] + 1) % 4;

        ex = ex + dx[dir];
        ey = ey + dy[dir];

        map[ex][ey] = true;

        dragon.push_back(dir);
    }
}
int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        dragon.clear();  //기존 드래곤 커브의 스택을 비워준다.

        map[x][y] = true;  //시작점 표시

        //0세대 좌표
        ex = x + dx[d];
        ey = y + dy[d];

        map[ex][ey] = true;

        dragon.push_back(d);

        for (int i = 0; i < g; i++)
        {
            curve(dragon);
        }
    }

    // 2.
    for (int i = 0; i <= 101 - 2; i++)
    {
        for (int j = 0; j <= 101 - 2; j++)
        {
            //인접한 4칸의 정사각형이 모두 드래곤의 일부이면
            if (map[i][j] == true && map[i][j + 1] == true && map[i + 1][j] == true && map[i + 1][j + 1] == true)
            {
                result++;
            }
        }
    }

    cout << result << '\n';
    return 0;
}