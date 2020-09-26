//7576. 토마토
#include <iostream>
#include <queue>

using namespace std;

int N,M;
int box[1001][1001];
queue<pair<int, int> > tomato;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int day = 0;
void bfs(){
    while(!tomato.empty()){
        int x = tomato.front().first;
        int y = tomato.front().second;
        tomato.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(box[nx][ny]==0){
                box[nx][ny] = box[x][y] + 1;
                tomato.push(make_pair(nx,ny));
            }
        }
    }
}
int main(){
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];
            if(box[i][j]==1) tomato.push(make_pair(i, j));
        }
    }

    bfs();

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j]==0){
                cout << -1 << "\n";
                return 0;
            }
            if(day < box[i][j]){
                day = box[i][j];
            }
        }
    }
    cout << day-1 << "\n";
    return 0;
}