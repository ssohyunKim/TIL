#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    char c;
    int count = 0;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> c;
            if(c == 'F' && (i+j)%2 == 0){ //짝수면 흰색
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}
