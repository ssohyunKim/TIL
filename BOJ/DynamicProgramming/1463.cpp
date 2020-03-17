#include <iostream>

using namespace std;
int d[1000000];

int solve(int n){
    if(n==1){
        return 0;
    }
    if(d[n] > 0) return d[n];
    d[n] = solve(n-1) + 1;
    if(n%3==0){
        int temp = solve(n/3) + 1;
        if(d[n] > temp){
            d[n] = temp;
        }
    }
    if(n%2==0){
        int temp = solve(n/2) + 1;
        if(d[n] > temp){
            d[n] = temp;
        }
    }
    return d[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int X;
    
    cin >> X;
    
    cout << solve(X) << "\n";
    
    return 0;
}