#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    char c;
    int arr[8][8];
    int count = 0;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> c;
            if(c == 'F'){
                arr[i][j] = 1;
            }else {
                arr[i][j] = 0;
            }
        }
    }
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            //cout << arr[i][j];
            if((i+j)%2 == 0 && arr[i][j]==1){ //짝수면 흰색
                count ++;
            }
        }
    }
    
    cout << count << "\n";
    return 0;
}
