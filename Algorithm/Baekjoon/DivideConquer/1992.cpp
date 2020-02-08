#include <iostream>

using namespace std;
int arr[64][64];

void compress(int x, int y, int n){ //x:x좌표, y:y좌표, n:사이즈
    bool flag = true;
    
    if(n==1){
        cout << arr[x][y];
        return;
    }
    
    int divide = n/2;
    int pixel = arr[x][y];
    for(int i=x; i<x+n && flag ; i++){
        for(int j=y; j<y+n && flag; j++){
            if(pixel!=arr[i][j]){
                flag = false;
            }
        }
    }

    if(flag){ // 모든 수가 같다면 출력한다.
        cout << pixel;
        return;
    }else{ // 같지 않았다면
        cout << '(';
        compress( x, y, divide);  //왼쪽 위
        compress( x, y+divide, divide); //오른쪽 위
        compress( x+divide, y, divide); //왼쪽 아래
        compress( x+divide, y+divide, divide); //오른쪽 아래
        cout << ')';
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    compress(0, 0, n);
    return 0;
}

