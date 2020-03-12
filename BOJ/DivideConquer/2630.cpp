#include <iostream>
#define MAX 8192;
using namespace std;
int arr[129][129];
int n, b, w;
void divide_conquer(int x, int y, int n){ //x:x좌표, y:y좌표, n:사이즈
    int m = arr[x][y];
    int divide = n/2;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[i][j] != m){
                divide_conquer(x, y, divide);
                divide_conquer(x, y+divide, divide);
                divide_conquer(x+divide, y, divide);
                divide_conquer(x+divide, y+divide, divide);
                return;
            }
        }
    }
    if(m == 1){
        b++;
    }else{
        w++;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    divide_conquer(0, 0, n);
    cout << w << "\n" << b << "\n";
    return 0;
}
