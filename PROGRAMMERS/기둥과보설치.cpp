// 2020 KAKAO 기둥과 보 설치
#include <iostream>
#include <vector>

using namespace std;

bool pillar[101][101];
bool beam[101][101];

bool check_pillar(int x, int y, int n)
{
    if (y == 0)
        return 1;
    if (pillar[x][y - 1])
        return 1;
    if (x > 0 && beam[x - 1][y])
        return 1;
    if (x < n && beam[x][y])
        return 1;

    return 0;
}

bool check_beam(int x, int y, int n)
{
    if (pillar[x][y - 1])
        return 1;
    if (x < n && pillar[x + 1][y - 1])
        return 1;
    if (x > 0 && x < n && beam[x + 1][y] && beam[x - 1][y])
        return 1;

    return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        //기둥 설치
        if (a == 0 && b == 1)
        {
            if (check_pillar(x, y, n))
            {
                pillar[x][y] = 1;
            }
        }
        //보 설치
        else if (a == 1 && b == 1)
        {
            if (check_beam(x, y, n))
            {
                beam[x][y] = 1;
            }
        }
        //기둥 삭제
        else if (a == 0 && b == 0)
        {
            bool can = 1;
            pillar[x][y] = 0;

            if (y < n && pillar[x][y + 1] && !check_pillar(x, y + 1, n))
                can = 0;
            else if (y < n && beam[x][y + 1] && !check_beam(x, y + 1, n))
                can = 0;
            else if (x > 0 && beam[x - 1][y + 1] && y < n && !check_beam(x - 1, y + 1, n))
                can = 0;

            if (!can)
                pillar[x][y] = 1;
        }
        //보 삭제
        else if (a == 1 && b == 0)
        {
            bool can = 1;
            beam[x][y] = 0;

            if (pillar[x][y] && !check_pillar(x, y, n))
                can = 0;
            else if (x < n && pillar[x + 1][y] && !check_pillar(x + 1, y, n))
                can = 0;
            else if (x > 0 && beam[x - 1][y] && !check_beam(x - 1, y, n))
                can = 0;
            else if (x < n && beam[x + 1][y] && !check_beam(x + 1, y, n))
                can = 0;

            if (!can)
                beam[x][y] = 1;
        }
    }

    // answer에 기둥과 보 상태 넣기
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (pillar[i][j])
            {
                answer.push_back({i, j, 0});
            }
            if (beam[i][j])
            {
                answer.push_back({i, j, 1});
            }
        }
    }
    return answer;
}
int main()
{
    vector<vector<int>> build_frame({vector<int>({1, 0, 0, 1}),
                                     vector<int>({1, 1, 1, 1}),
                                     vector<int>({2, 1, 0, 1}),
                                     vector<int>({2, 2, 1, 1}),
                                     vector<int>({5, 0, 0, 1}),
                                     vector<int>({5, 1, 0, 1}),
                                     vector<int>({4, 2, 1, 1}),
                                     vector<int>({3, 2, 1, 1})});
    vector<vector<int>> a = solution(5, build_frame);

    for(int i=0; i<ve)

    return 0;
}