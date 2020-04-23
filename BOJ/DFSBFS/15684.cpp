//사다리조작
#include <iostream>

using namespace std;

int n, m, h;
int line; // 추가한 가로 선 개수
bool flag;
int ans;
int min = 999999;

//사다리에 선 추가하기
void addLine(int cnt, int k){
    // 이미 답을 찾은 경우
    if(flag){ 
        return;
    }
    // 개수를 다 쓴 경우
    if(cnt == h){
        bool possible = true;
        for(int i=0; i<n; i++){
            int row = i; // 가로
            for(int j=0; j<h; j++){
                if(ladder[j][row])
                    row++;
                else if(row > 1 && ladder[j][row])
                    row--;
            }

            // i번 세로선의 결과가 i번이 나와야한다.
            
        }
        return;
    }

}
int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> n >> m >> h;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        // a번째에서 b~b+1을 이어주는 사다리
        ladder[a][b] = true;

        for(int i=0; i<3; i++){
            line = i;

            addLine(0, 0);

            // 사다리번호가 i번째가 맞으면 그때의 최솟값을 출력
            if(){
                ans = min;
            }else{
                ans = -1;
            }

        }
    }
    cout << ans << '\n';

    return 0;
}