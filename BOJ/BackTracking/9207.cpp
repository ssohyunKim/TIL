#include <iostream>

using namespace std;

char map[6][10];

// 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int p_num, m_num;
int num;

void dfs(int x, int y, int n){
    if(p_num == 0 || p_num > n){
        p_num = n;
        m_num = num - n;
    }
    
    for(int k=0; k<4; k++){
        // 다음 칸
        int nx = x+dx[k]; 
        int ny = y+dy[k];
        
        if(nx < 0 || ny < 0 || nx >= 5 || ny >=9 ) continue;

        // 다음 칸이 o이고  
        if(map[nx][ny] == 'o'){
            // 다음다음칸
            int nnx = nx + dx[k];
            int nny = ny + dy[k];
            if(nnx < 0 || nny < 0 || nnx >= 5 || nny >=9 ) continue;

            // 다음 다음 칸이 비어있으면
            if(map[nnx][nny] == '.'){
                map[x][y] = map[nx][ny] = '.';
                map[nnx][nny] = 'o';

                for(int i=0; i<5; i++){
                    for(int j=0; j<9; j++){
                        if(map[i][j] == 'o'){
                            dfs(i, j, n-1);
                        }
                    }
                }
                map[x][y] = map[nx][ny] = 'o';
                map[nnx][nny] = '.';
            }
        }
    }    
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    while(n--){
        p_num = m_num = 0;
        int cnt = 0; // 핀 개수 체크
        for(int i=0; i<5; i++){
            for(int j=0; j<9; j++){
                cin >> map[i][j];
                if(map[i][j]=='o') cnt ++;
            }
        }
        num = cnt;
        for(int i=0; i<5; i++){
            for(int j=0; j<9; j++){
                if(map[i][j] == 'o'){
                    dfs(i, j, cnt);
                }
            }
        }

        cout << p_num << " " << m_num << "\n";
    }
   
    return 0;
}
