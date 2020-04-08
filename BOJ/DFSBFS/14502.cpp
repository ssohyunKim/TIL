#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1. 벽을 세우는 것
// 2. 바이러스를 퍼트리는 것

int n, m;
int map[8][8];
int temp[8][8];
// 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans;

void bfs();
// 벽 만들기
void dfs(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(temp[i][j]==0){
                temp[i][j] = 1;
                dfs(cnt+1);
                temp[i][j] = 0;
            }
        }
    }
}
// 바이러스 퍼트리기
void bfs(){
    queue<pair<int,int> > q;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(map[nx][ny]==0){
                    map[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    // 개수 세기
    int temp=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==0)
                temp++;
        }
    }
 
    if(temp>ans){
        ans = temp;
    }
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
            temp[i][j] = map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==0){
                temp[i][j] = 1;
                dfs(1);
                temp[i][j] = 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}