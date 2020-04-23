//사다리조작
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, h, ans;
int ladder[31][11];

//사다리탈 수 있는지 없는지 체크하기 위한 함수
bool check(){
    bool flag = true;
    for(int i = 1; i <= n; i++){
        int pos = i; // 가로선 i부터 시작

        for(int j = 0; j <= h; j++){
            if(ladder[j][pos] == 1){
                pos++;
            }else if(ladder[j][pos-1] == 1){
                pos--;
            }
        }
        if(pos != i){
            return flag = false;
        }
    }
    return flag;
}

//사다리에 선 추가하기
void dfs(int x, int y, int cnt){
    if(cnt >= ans) return;
    if(check()){
        ans = cnt;
        return;
    }
    if(cnt == 3) return;
    for(int i = y; i <= h; i++){ // 세로
        for(int j = x; j < n; j++){  // 가로 줄의 마지막은 넣을 수 없다.
            //선을 그을 수 있으면
            if(ladder[i][j] == 0 && ladder[i][j-1] == 0 && ladder[i][j+1] == 0){
                ladder[i][j] = 1;
                dfs(i, j, cnt+1);
                ladder[i][j] = 0;
            }
        }
        x = 1;
    }
}
int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> h;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        // b세로선과 b+1세로선을 연결하는 a번째 가로선이 있다.  
        ladder[a][b] = 1;
    }
    
    ans = 4;
    dfs(1, 1, 0);
    if(ans == 4){
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}