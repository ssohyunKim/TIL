#include <iostream>
#include <algorithm>

using namespace std;

int wine[10001];
int d[10001];
int n;

int dp(int n){
    d[1] = wine[1];
    d[2] = wine[1] + wine[2];
   
    for(int i=3; i<=n; i++){
        int temp = max(d[i-1], d[i-2] + wine[i]);
        d[i] = max(temp, d[i-3] + wine[i-1] + wine[i]);
    }
    return d[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> wine[i];
    }

    cout << dp(n) << "\n";

    return 0;
}