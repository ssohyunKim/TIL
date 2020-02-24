#include <iostream>
using namespace std;

int arr[5];
int check(){
    for(int i=0; i<5; i++){
        if(arr[i] != i+1){
            return -1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
   
    int temp;
    
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }
    
    while(check()==-1){
        for(int i=0; i<4; i++){
            for(int j=i+1; j<i+2; j++){
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    
                    //printf("%d %d\n", i, j);
                    
                    for(int i=0; i<5; i++){
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                }
                else{
                    continue;
                }
            }
        }
    }
    return 0;
}

