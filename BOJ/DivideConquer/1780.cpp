//1780. 종이의 개수
#include <iostream>
#include <vector>

using namespace std;

int n;
int map[2187][2187];
int minusone = 0, zero = 0, one = 0;
void cut(int x, int y, int size){
    int value = map[x][y];

    if(size==1){
        if(value == -1) {
            minusone ++;
            return;
        }else if(value == 0){ 
            zero ++;
            return;
        }else {
            one ++; 
            return;
        }
    }

    bool check = true;
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(map[i][j]!=value){
                check = false;
                break;
            }
        }
    }
    if(check){
        if(value == -1) minusone ++;
        else if(value == 0) zero ++;
        else one ++; 
        return;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cut(x+size*i/3, y+size*j/3, size/3);
        }
    }
    // cut(x, y, size/3);
    // cut(x, y+size/3, size/3);
    // cut(x, y+size*2/3, size/3);

    // cut(x+size/3, y, size/3);
    // cut(x+size/3, y+size/3, size/3);
    // cut(x+size/3, y+size*2/3, size/3);

    // cut(x+size*2/3, y, size/3);
    // cut(x+size*2/3, y+size/3, size/3);
    // cut(x+size*2/3, y+size*2/3, size/3);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    cut(0, 0, n);

    cout << minusone << "\n" << zero << "\n" << one << "\n";

    return 0;
}