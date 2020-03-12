#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 30

using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];
// 상, 하, 좌, 우
int dx[] = { -1, 1, 0, 0};
int dy[] = { 0, 0, -1, 1};
int cnt; // 단지 갯수
vector<int> v; // 집 갯수

void dfs(int x, int y){
    cnt ++;
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if(map[nx][ny] == 1 && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                cnt = 0;
                dfs(i,j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    
    printf("%ld\n", v.size());
    for(int i=0; i<v.size(); i++){
        printf("%d\n", v[i]);
    }
    
    return 0;
}

