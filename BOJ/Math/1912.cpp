#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int array[100000];
    int sum = 0;
    int result = -2000;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    
    for(int i=0; i<n; i++){
        if(sum + array[i] >0){
            sum += array[i];
            result = max(result, sum);
        }else{
            result = max(result, sum+array[i]);
            sum = 0;
        }
        //printf("%d: %d %d\n", i, sum, result);
    }
    cout << result << "\n";
    return 0;
}
