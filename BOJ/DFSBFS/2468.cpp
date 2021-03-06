#include <iostream>
#include <algorithm>
#define MAX 100

using namespace std;

int n,result;
int map[MAX][MAX] = {0, };
bool visited[MAX][MAX] ={0, };
// 상,하,좌,우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
 
void dfs(int x, int y, int height) {
    visited[x][y] = 1;
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= n || ny >= n){ //배열 인덱스 안 넘게끔
            continue;
        }
        if (map[nx][ny] > height && !visited[nx][ny]){
            dfs(nx, ny, height);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    int maxDepth = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            maxDepth = max(maxDepth, map[i][j]);
        }
    }
    
    for (int height = 0; height <= maxDepth; height++) {
        int safeNum = 0;
        memset(visited, 0, sizeof(visited));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] > height && !visited[i][j]) {
                    dfs(i, j, height);
                    safeNum++;
                }
            }
        }
        result = max(result, safeNum);
    }
    cout << result << endl;

    return 0;
}

// + BFS풀이 추가)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <queue>
// #define MAX 100

// using namespace std;

// int n,result;
// int map[MAX][MAX];
// bool visited[MAX][MAX];
// // 상,하,좌,우
// int dx[] = { -1, 1, 0, 0 };
// int dy[] = { 0, 0, -1, 1 };
 
// void BFS(int a, int b, int h)
// {
//     queue<pair<int, int>> q;
//     q.push(make_pair(a, b));
//     visited[a][b] = true;
//     while (!q.empty())
//     {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();
 
//         for (int i = 0; i < 4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (nx >= 0 && ny >= 0 && nx < n && ny < n){
//                 if (visited[nx][ny] == false && map[nx][ny] > h){
//                     visited[nx][ny] = true;
//                     q.push(make_pair(nx, ny));
//                 }
//             }
//         }
//     }
// }

// int main(int argc, const char * argv[]) {
//     // insert code here...
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n;
    
//     int maxDepth = 0;
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> map[i][j];
//             maxDepth = max(maxDepth, map[i][j]);
//         }
//     }
    
//     for (int height = 0; height <= maxDepth; height++) {
//         int safeNum = 0;
//         memset(visited, 0, sizeof(visited));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (map[i][j] > height && !visited[i][j]) {
//                     safeNum++;
//                     BFS(i,j,height);
//                 }
//             }
//         }
//         result = max(result, safeNum);
//     }
//     cout << result << endl;

//     return 0;
// }

