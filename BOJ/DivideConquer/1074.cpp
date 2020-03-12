#include <iostream>
#define MAX 8192;
using namespace std;
int s = 1;
int arr[32768][32768];
int cnt = 0;
int N, r, c;
void divide_conquer(int x, int y, int n){ //x:x좌표, y:y좌표, n:사이즈
    if(n == 1){
        if(x == r && y == c){ // 입력받은 (r,c)와 (x,y)좌표값이 같을때
            cout << cnt << "\n";
        }
        cnt++;  //아니면 계속 증가
        return;
    }
    int divide = n/2;
    
    // 재귀호출 Z가 그려지는 사분면의 각 시작점 좌표값
    divide_conquer(x, y, divide);
    divide_conquer(x, y+divide, divide);
    divide_conquer(x+divide, y, divide);
    divide_conquer(x+divide, y+divide, divide);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> r >> c;
    
    //사이즈 구하기-STL사용하여 pow(2,N)도 가능
    for(int i=0; i<N; i++){
        s *= 2;
    }
    
    divide_conquer(0, 0, s);

    return 0;
}

// +) 다른 풀이
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <string>
// #include <math.h>
// using namespace std;
// int res=0;
// int N,R,C;

// void solve(int n, int r, int c)
// {
//    if(n==2)
//    {
//       //찾으려던 곳일 경우 
//       if(r==R && c==C)
//       {
//          cout << res;
//          return;
//       }
//       res++;
//       if(r==R && c+1==C)
//       {
//          cout << res;
//          return;
//       }
//       res++;
//       if(r+1==R && c==C)
//       {
//          cout << res;
//          return;
//       }
//       res++;
//       if(r+1==R && c+1==C)
//       {
//          cout << res;
//          return;
//       }
//       res++;
//       return;
      
//    }
//    //분할 된 부분의 첫부분을 재귀로 넘겨줌 
//    solve(n/2, r, c);
//    solve(n/2, r, c+n/2);
//    solve(n/2, r+n/2, c);
//    solve(n/2, r+n/2, c+n/2);   
// }


// int main() {
//    //freopen("input.txt", "rt", stdin);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
   
//    cin >> N >> R >> C;
   
//    solve(pow(2, N), 0 , 0);    
//    return 0;

// }