#include <iostream>

using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];

// 북, 동, 남, 서 
int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};
// 서, 북, 동, 남
int bx[] = { 1, 0, -1, 0};
int by[] = { 0, -1, 0, 1};
int cnt = 0;

void dfs(int x, int y, int d){
    bool flag = true;

    if(map[x][y] == 0){ //청소가 가능한 칸인지 체크
        cnt ++;
        map[x][y] = 2; //청소했음
    }
    for(int i=d-1; i>d-5; i--){
        int dir = (i+4)%4; //방향전환
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

        if(map[nx][ny] == 0){ //청소가 가능한 칸인지 체크 
            dfs(nx, ny, dir);
            return;
        }
    }
    if(map[x+bx[d]][y+by[d]] == 1){ //후진이 불가능한 칸
        flag = false; 
    }else if(flag){ //후진이 가능한 칸
        dfs(x+bx[d], y+by[d], d);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c, d;
    
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }    
    dfs(r, c, d);
    cout << cnt <<"\n";
    return 0;
}
