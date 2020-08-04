// 15684. 사다리조작
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H, answer;
int map[11][30];
bool visited[11][30];

bool ladder()
{
    for (int i = 1; i <= N; i++)
    {
        int current = i;
        for (int j = 1; j <= H; j++)
        {
            if (visited[current][j] == true)
                current = current + 1;
            else if (visited[current - 1][j] == true)
                current = current - 1;
        }

        if (current != i)
            return false;
    }
    return true;
}

void select(int Idx, int cnt)
{
    if (cnt >= 4)
        return;

    if (ladder() == true)
    {
        answer = min(answer, cnt);
        return;
    }

    for (int i = Idx; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (visited[j][i] == true)
                continue;
            if (visited[j - 1][i] == true)
                continue;
            if (visited[j + 1][i] == true)
                continue;

            visited[j][i] = true;
            select(i, cnt + 1);
            visited[j][i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    answer = 9999999;
    cin >> N >> M >> H;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        visited[b][a] = true;
    }

     select(1, 0);

    if (answer == 9999999)
        answer = -1;

    cout << answer << "\n";

    return 0;
}