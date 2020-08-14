//9207.페그 솔리테어
#include <iostream>
#include <vector>

using namespace std;

int N;
char MAP[6][10];
int PIN_COUNT, MOVE_COUNT;
int cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int n){
    if(PIN_COUNT == 0 || n < PIN_COUNT){
        PIN_COUNT = n;
        MOVE_COUNT = cnt - n;
    }

    for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx<0||ny<0||nx>=5||ny>=9) continue;
        //인접한 칸에 핀이 있고
        if(MAP[nx][ny]=='o'){
            int nnx = nx + dx[k];
            int nny = ny + dy[k];

            if(nnx<0||nny<0||nnx>=5||nny>=9) continue;
            //인접한 칸 다음칸이 빈칸이면
            if(MAP[nnx][nny]=='.'){
                //인접한 칸 다음칸에 핀을 두고, 인접한 칸의 핀을 제거한다
                MAP[x][y] ='.';
                MAP[nx][ny] = '.';
                MAP[nnx][nny] = 'o';

                for(int i=0; i<5; i++){
                    for(int j=0; j<9; j++){
                        if(MAP[i][j]=='o'){
                            dfs(i, j, n-1);
                        }
                    }
                }
                //원래대로 돌리기
                MAP[x][y] = 'o';
                MAP[nx][ny] = 'o';
                MAP[nnx][nny] = '.';
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int test_case=0; test_case<N; test_case++){
        cnt = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<9; j++){
                cin >> MAP[i][j];
                
                //핀이 꽂혀있는 칸의 자리 개수
                if(MAP[i][j]=='o'){
                    cnt++;
                }
            }
            PIN_COUNT = cnt;
            MOVE_COUNT = 0;
            for(int i=0; i<5; i++){
                for(int j=0; j<9; j++){
                    if(MAP[i][j] == 'o'){
                        dfs(i, j, cnt);
                    }
                }
            }
        }
        cout << PIN_COUNT << " " << MOVE_COUNT << "\n";
    }
    return 0;
}