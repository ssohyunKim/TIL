// 9663. N-Queen
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, answer = 0;
int col[16];

bool isPossible(int level)
{
    //배치가능한지 여부
    //col[level]은 level행 *열
    //col[2] = 3 -> 2행 3열
    for (int i = 1; i < level; i++)
    {
        //같은 열이거나 대각선이면 배치 못함
        //x좌표의 차 , y좌표의 차
        if (col[level] == col[i] || abs(col[level] - col[i]) == level - i)
        {
            return false;
        }
    }

    return true;
}

void dfs(int level)
{
    //판이 완성
    if (level == N)
    {
        answer++;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            //해당 열에 배치
            col[level + 1] = i;
            if (isPossible(level + 1))
            {
                dfs(level + 1);
            }
            else
            {
                col[level + 1] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dfs(0);
    cout << answer;

    return 0;
}