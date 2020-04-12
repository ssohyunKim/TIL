#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 1. 벽을 세우는 것
// 2. 바이러스를 퍼뜨리는 것

int n, m;
int map[8][8];
int ans = 0;
vector<pair<int, int> > v;
// 상, 하, 좌, 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs();

// 벽 만들기
void dfs(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==0){
                map[i][j] = 1; 
                dfs(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}
// 바이러스 퍼트리기
void bfs(){
    int temp[8][8];
    memcpy(temp, map, sizeof(map));
    queue<pair<int,int> > q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(temp[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            
            // 벽 세우기
            if(temp[nx][ny]==0){
                temp[nx][ny] = 2;
                q.push(make_pair(nx,ny));
            }
        }
    }
    
    // 안전구역의 개수 세기
    int safe=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(temp[i][j]==0)
                safe++;
        }
    }
    //최대값 계산
    ans = max(ans, safe);
}
int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(map[i][j]==0){
    //             map[i][j] = 1;
    //             dfs(1);
    //             map[i][j] = 0;
    //         }
    //     }
    // }
    dfs(0);

    cout << ans << "\n";

    return 0;
}