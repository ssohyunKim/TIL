#include <iostream>
using namespace std;
int n;
char arr[6560][6560];

void Star(int x, int y, int number){
    if(number == 1){
        arr[x][y] = '*';
        return;
    }
    int div = number/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1){
                continue;
            }
            Star(x+(div*i),y+(div*j), div);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < 6560; i++) {
        for (int j = 0; j < 6560; j++) {
            arr[i][j]=' ';
        }
    }
    
    Star(0,0,n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
