#include <iostream>
#include <algorithm>

#define MAX 51

using namespace std;

int n,m;
char map[MAX][MAX];
int result = 9999999;
void paint(int x, int y){
    int cntW = 0;
    int cntB = 0;
    for(int i=x; i<x+8; i++){
        for(int j=y; j<y+8; j++){
            if((i + j) % 2 == 0){ // 짝수
                if(map[i][j] == 'B')
                    cntW ++;
                else
                    cntB ++;
            }else {               // 홀수
                if(map[i][j] == 'B')
                    cntB ++;
                else
                    cntW ++;
            }
        }
    }
    result = min(result, cntB);
    result = min(result, cntW);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    int a = n - 8;
    int b = m - 8;

    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            paint(i, j);
        }
    }
    
    cout << result << '\n';
    
    return 0;
}

