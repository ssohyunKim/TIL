#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int rx, ry, bx, by; // 공의 위치
int hx, hy; // 구멍 위치
bool flag;
char map[10][10];
bool visitied[10][10][10][10];
int cnt = 0; 
queue<pair<int,int> > r;
queue<pair<int,int> > b;

// 상, 하, 좌, 우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

// 1. 빨간 구슬 이동시키기
// 2. 파란 구슬 이동시키기

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                r.push(make_pair(i, j)); // 빨간 구슬 위치 저장
            }else if(map[i][j] == 'B'){
                b.push(make_pair(i, j)); // 파란 구슬 위치 저장
            }
        }
    }

    visited[rx][ry][bx][by] = true;

    while (!r.empty())
    {
        int qsize = r.size();
 
        while (qsize--)
        {
            rx = r.front().first;
            ry = r.front().second;
            bx = b.front().first;
            by = b.front().second;
            r.pop(); b.pop();
 
            if (cnt > 10) { // 10번 초과하면 
                break;
            }
           
            if (rx == hx && ry == hy) {  // 빨간 구슬이 구멍에 빠지면 
                flag = true; 
                break;
            }
 
            for (int i = 0; i < 4; i++)
            {
                int nrx = rx + dx[i];
                int nry = ry + dy[i];
                int nbx = bx + dx[i];
                int nby = by + dy[i];
 
                // 상하좌우 방향으로 구슬 움직이기
                while (1)
                {
                    if (board[nrx][nry] == '#') {
                        nrx -= dx[i]; 
                        nry -= dy[i];
                        break;
                    }
                    if (board[nrx][nry] == 'O') break;
                    nrx += dx[i]; 
                    nry += dy[i];
                }
                while (1)
                {
                    if (board[nbx][nby] == '#') {
                        nbx -= dx[i]; 
                        nby -= dy[i];
                        break;
                    }
                    if (board[nbx][nby] == 'O') break;
                    nbx += dx[i]; 
                    nby += dy[i];
                }
 
                // 파란 구슬이 구멍에 빠지면 continue
                if (nbx == hx && nby == hy) continue;
 
                // 같은 위치에 두 개의 구슬이 있으면 위치 갱신
                if (nrx == nbx && nry == nby)
                {
                    switch (i){
                    case 0: rx > bx ? nrx++ : nbx++; break;
                    case 1: rx < bx ? nrx-- : nbx--; break;
                    case 2: ry > by ? nry++ : nby++; break;
                    case 3: ry < by ? nry-- : nby--; break;
                    }
                }
                
                // 방문했던 지점이 아니면 push
                if (visited[nrx][nry][nbx][nby]) continue;
                r.push(make_pair(nrx, nry));
                b.push(make_pair(nbx, nby));
                visited[nrx][nry][nbx][nby] = true;
            }
        }
        if (flag) break;
        else cnt++;
    }
 
    if (flag) cout << cnt;
    else cout << -1;

    return 0;
}
