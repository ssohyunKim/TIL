#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct SHARK{
    int y, x, time;
};

int n;
int map[20][20];
int size, eat;
SHARK shark;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> map[y][x];
            //상어의 위치 기록
            if(map[y][x] == 9) {  
                shark.y = y, shark.x = x, shark.time = 0;
                size = 2;
                eat = 0;
                map[y][x] = 0;
            }
        }
    }
    //상어가 먹은게 있는지 없는지 체크
    bool flag = true; 
    while(flag){
        flag = false;

        bool visited[20][20] = {false, };
        queue<SHARK> q;
        visited[shark.y][shark.x] = true;
        q.push(shark);

        SHARK candi;
        candi.y = 20; //맵의 가장 큰값으로 초기화
        candi.time = -1;
        while(!q.empty()){
            SHARK cur = q.front(); 
            q.pop();

            // 가장 가까운 물고기를 먹야야 하므로 이 조건에 걸리면 이미 잡은 것
            if(candi.time != -1 && candi.time < cur.time){ 
                break;
            }

            // 먹을 수 있는 물고기가 존재하면
            if(map[cur.y][cur.x] < size && map[cur.y][cur.x] !=0) {
                flag = true;
                if(candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)){
                    candi = cur;
                }
            }

            for(int dir = 0; dir < 4; dir++){
                SHARK next;
                next.y = cur.y + dy[dir];
                next.x = cur.x + dx[dir];
                next.time = cur.time + 1;

                if(next.y < 0 || next.y >=n || next.x < 0 || next.x >=n){
                    continue;
                }
                // 방문하지 않았고 상어의 크기보다 물고기가 작다면 아니라면
                if(!visited[next.y][next.x] && size >= map[next.y][next.x]){
                    visited[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }
        if(flag) {
            shark = candi;
            eat ++;
            if(eat == size){
                size ++;
                eat = 0;
            }
            map[shark.y][shark.x] = 0;
        }
    }
    ans = shark.time;

    cout << ans << "\n";

    return 0;
}