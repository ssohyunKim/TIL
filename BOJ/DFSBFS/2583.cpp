#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int m,n,k;
int map[101][101] = {0,};
bool visited[101][101];
vector<int> v;
//상, 하, 좌, 우
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int x, y, z, w;
int cnt;

void BFS(int a, int b){
    cnt = 1;
    queue<pair<int,int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m){
                continue;
            }
            if(map[nx][ny]==0 && !visited[nx][ny]){
                cnt ++;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    v.push_back(cnt);
}
void draw(int a, int b, int c, int d){
    for(int i=a; i<c; i++){
        for(int j=b; j<d; j++){
            map[i][j] = 1;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k;
    
    for(int i=0; i<k; i++){
        cin >> x >> y >> z >> w;
        draw(x, y, z, w);
    }
    
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << map[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==0 && !visited[i][j]){
                BFS(i, j);
            }
        }
    }
    sort(v.begin(), v.end());

    cout << v.size() << "\n";

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}
