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

