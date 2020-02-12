#include <iostream>
#include <algorithm>

#define MAX 10000
using namespace std;
int n,k;
int line[MAX+1];

void binarySearch(long long first, long long last){
    long long result = 0;
    while(first <= last){
        long long mid = (first+last)/2;
        
        int cnt = 0;
        for(int i=0; i<k; i++){
            cnt += line[i]/mid;
        }
        
        if(cnt >= n){
            first = mid+1;
            if(result < mid){
                result = mid;
            }
        }else{
            last = mid-1;
        }
    }
    cout << result << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> k >> n;
    
    for(int i=0; i<k; i++){
        cin >> line[i];
    }
      
    long long high = *max_element(line, line+k);
    
    binarySearch(0, high);
    return 0;
}

