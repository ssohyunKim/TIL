// 3055. 탈출
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 비어있는 곳은 '.', 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 
// 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.
// 고슴도치는 (위, 아래, 오른쪽, 왼쪽)로 이동. 물도 매 분마다 비어있는 칸으로 확장한다
// 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력
// 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 

// - 물이 1초마다 움직이므로 함수를 작성해 계산해준다.
// - 물의 위치를 담은 큐를 선언하고, 매 초마다 큐에 있는 물을 꺼내서 주변의 위치를 다시 큐에 넣는다.
// - 고슴도치의 위치를 담은 큐를 선언하고, 고슴도치가 이동할 수 있는 위치를 큐에 넣는다.
// - 매 초마다 큐에서 꺼내서 다시 이동할 수 있는 주변위치를 큐에 넣는다.
// - 고슴도치가 비버의 굴(D)에 도착하면 결과값을 리턴한다.

char map[51][51]; // 지도
int d[51][51];  // 물이 차오르는 시간
int t[51][51];  // 이동하는데 걸리는 시간
int sx,sy,fx,fy;
int R, C;
int dx[] = { -1, 1, 0, 0};
int dy[] = { 0, 0, 1, -1};

queue<pair<int, int> > w;

void water(){
    while(!w.empty()){
        int x = w.front().first;
        int y = w.front().second;
        w.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||ny<0||nx>=R||ny>=C) continue;
            if(d[nx][ny]==0 && map[nx][ny]=='.'){
                d[nx][ny] = d[x][y] + 1;
                w.push(make_pair(nx, ny));
            }
        }
    }
}
void move(){
    queue<pair<int, int> >  q;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||ny<0||nx>=R||ny>=C) continue;

            if(t[nx][ny]==0 && (map[nx][ny]=='.'||map[nx][ny]=='D')){
                //도착점은 바로 큐에 넣어준다.
                if(d[nx][ny]==0){
                    t[nx][ny] = t[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }else{
                    //이동하려는 칸이 다음날 물이 차오르지 않으면 큐에 넣어준다.
                    if(d[nx][ny] > t[x][y]+1){
                        t[nx][ny] = t[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            } 
        }
    }
}
int main(){
    scanf("%d %d", &R, &C);

    for(int i=0; i<R; i++){
        //scanf("%s", map[i]);
        for(int j=0; j<C; j++){
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'S'){
                sx = i;
                sy = j;
            }else if(map[i][j] == 'D'){
                fx = i;
                fy = j;
            }else if(map[i][j] == '*'){
                w.push(make_pair(i, j));
            }
        }
    }

    water();
    move();

    if(t[fx][fy]==0){
        printf("KAKTUS\n");
    }else{
        printf("%d\n", t[fx][fy]);
    }
    return 0;
}