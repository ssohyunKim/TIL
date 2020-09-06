// 1941. 소문난 칠공주
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
 
using namespace std;
 
int map[5][5], answer = 0;
bool visited[25];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 ,0, 0 };
 
bool MoreThanFour()
{
    int cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (visited[i]) // 번호를 좌표로 바꾸기
        {
            int x = i / 5;
            int y = i % 5;
 
            if (map[x][y] == 2) cnt++;
        }
    }
    if (cnt >= 4) return true;
    else return false;
}
 
bool adjacency()
{
    queue <pair<int, int>> q;
    bool check_visited[5][5];
    bool queue_visited[5][5];
    bool check_answer = false;
 
    memset(queue_visited, false, sizeof(queue_visited));
    memset(check_visited, false, sizeof(check_visited));
 
    int tmp = 0;
    for (int i = 0; i < 25; i++)
    {
        if (visited[i] == true)
        {            
            int x = i / 5;
            int y = i % 5;
            check_visited[x][y] = true;
 
            if (tmp == 0)
            {
                q.push(make_pair(x, y));
                queue_visited[x][y] = true;
                tmp++;
            }
        }
    }
 
    int cnt = 1;
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        if (cnt == 7)
        {
            check_answer = true;
            break;
        }
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            {
                if (check_visited[nx][ny] == true && queue_visited[nx][ny] == false)
                {
                    queue_visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
    }
 
    if (check_answer == true) return true;
    return false;
}
void dfs(int idx, int cnt) //25명 중에서 7명 뽑기
{
    if (cnt == 7)
    {
        // 이다솜파가 4명 이상 있는 지 확인
        if (MoreThanFour())
        {
            // 뽑은 7명이 서로 인접해 있으면 결과값 증가
            if (adjacency()) answer++;
        }
        return;
    }
 
    for (int i = idx; i < 25; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'Y') map[i][j] = 1;
            else if (s[j] == 'S') map[i][j] = 2;
        }
    } 

    dfs(0, 0);
    cout << answer << "\n";
 
    return 0;
}