// 1063. 킹
#include <iostream>
#include <vector>
#include <string.h>

// 체스판의 위치는 알파벳은 열을 상징하고, 숫자는 행을 상징한다.
// 오(R), 왼(L), 아(B), 위(T), 오대(RT), 위대(LT), 아대(RB), 아대(LB)
// 킹이 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다.
// 킹과 돌의 마지막 위치를 구하는 프로그램
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    char K[3], S[3], D[3];
    int N; 
    int x, y;
    cin >> K >> S >> N;
    for(int i=0; i<N; i++){
        // 초기화
        x=0, y=0; 
        D[0]=0, D[1]=0;

        cin >> D;

        if(D[0]=='L'){
            x--;
            if(D[1]=='T') y++;
            else if(D[1]=='B') y--;
        }else if(D[0]=='R'){
            x++;
            if(D[1]=='T') y++;
            else if(D[1]=='B') y--;
        }else if(D[0]=='B'){
            y--;
        }else if(D[0]=='T'){
            y++;
        }

        //체스판 밖으로 나가면
        if(K[0]+x<'A' || K[1]+y<'1' || K[0]+x>'H' || K[1]+y>'8') continue;

        K[0] += x;
        K[1] += y;

        //같은 곳일 때 돌은 킹이 움직인 방향과 같은 방향으로 한 칸 이동
        if(K[0]==S[0] && K[1]==S[1]){
            if(S[0]+x<'A' || S[1]+y<'1' || S[0]+x>'H' || S[1]+y>'8'){
                K[0] -= x;
                K[1] -= y;
                continue;
            }
            S[0] += x;
            S[1] += y;
        }
    }
    cout << K << '\n';
    cout << S;
    
    return 0;
}