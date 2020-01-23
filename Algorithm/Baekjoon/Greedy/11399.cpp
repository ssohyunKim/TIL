#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int a[1000];
    int temp=0, sum=0;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    sort(a, a+n); //오름차순으로 정렬 1 2 3 4 5
    
    for(int i=0; i<=n; i++){ //인출하는 데 걸리는 시간. 1 3 6 9 13
        temp += a[i];
        a[i] = temp;
    }
    
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    
    cout << sum << "\n";
    return 0;
}



