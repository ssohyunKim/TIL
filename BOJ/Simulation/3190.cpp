#include <iostream>
#include <vector>
#include <deque>

#define MAX 100
using namespace std;

int N, K, L;
int MAP[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<pair<int, char>> V;

int Turn_Direction(int d, char c)
{
    if (c == 'L')
    {
        if (d == 0)
            return 3;
        else if (d == 1)
            return 2;
        else if (d == 2)
            return 0;
        else if (d == 3)
            return 1;
    }
    else if (c == 'D')
    {
        if (d == 0)
            return 2;
        else if (d == 1)
            return 3;
        else if (d == 2)
            return 1;
        else if (d == 3)
            return 0;
    }
    return -1;
}

void Solve()
{
    deque<pair<int, int>> dq;
    int x = 0;
    int y = 0;
    int d = 0;
    int Time = 0;
    int Idx = 0;
    dq.push_back(make_pair(x, y));
    MAP[x][y] = 2;

    while (1)
    {
        Time++;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if ((nx < 0 || ny < 0 || nx >= N || ny >= N) || MAP[nx][ny] == 2)
        {
            break;
        }
        else if (MAP[nx][ny] == 0)
        {
            MAP[nx][ny] = 2;
            MAP[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
            dq.push_front(make_pair(nx, ny));
        }
        else if (MAP[nx][ny] == 1)
        {
            MAP[nx][ny] = 2;
            dq.push_front(make_pair(nx, ny));
        }

        if (Idx < V.size())
        {
            if (Time == V[Idx].first)
            {
                if (V[Idx].second == 'L')
                    d = Turn_Direction(d, 'L');
                else if (V[Idx].second == 'D')
                    d = Turn_Direction(d, 'D');
                Idx++;
            }
        }
        x = nx;
        y = ny;
    }
    cout << Time << endl;
}

int main(int argc, const char *argv[])
{
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        MAP[x][y] = 1; // 사과 = 1로 표시
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }

    Solve();

    return 0;
}