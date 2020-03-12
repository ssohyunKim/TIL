#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k;
    int a[11];
    int result = 0;
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=n-1; i>=0; i--){
        if(k==0){
            break;
        }
        if(k/a[i] == 0){
            continue;
        }
        result += k/a[i];
        k = k - a[i]*(k/a[i]);
    }
    
    cout << result << "\n";
    return 0;
}


