#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100

using namespace std;

int n;
char c; // R, G, B 입력받기위해
int map[MAX][MAX];
bool visited[MAX][MAX];
// 상,하,좌,우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int nomal, abnomal = 0;

void dfs(int x, int y){
    visited[x][y] = true;
    int val = map[x][y];
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >=n || ny >= n)
            continue;
        
        if(map[nx][ny] == val && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if(c == 'R'){
                map[i][j]=1; // 빨강
            }else if(c == 'B'){
                map[i][j]=2; // 파랑
            }else{
                map[i][j]=3; // 초록
            }
            
        }
    }
    
   // 정상 사람일 때
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]){
                nomal++;
                dfs(i,j);
            }
        }
    }
    
    // 적록 색약인 사람
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] == 3){ // 초록이면 빨강으로 바꿔줬다
                map[i][j] = 1;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]){
                abnomal++;
                dfs(i,j);
            }
        }
    }

    cout << nomal << ' ' << abnomal << '\n';

    return 0;
}