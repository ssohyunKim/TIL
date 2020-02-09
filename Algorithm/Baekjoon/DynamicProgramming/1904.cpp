#include <iostream>
#include <algorithm>

#define max 1000001
using namespace std;
int n;
long long arr[max];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    if(n==1){
        cout << 1;
    }else if(n==2){
        cout << 2;
    }else{
        for(int i=3; i<=n; i++){
            arr[i] = (arr[i-1] + arr[i-2]) % 15746;
        }
        cout << arr[n] ;
    }
    cout << "\n";
}

