#include <iostream>

using namespace std;

int n;
long long int d[91];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 1;
    
    for(int i=3; i<=n; i++){
        d[i] = d[i-1] + d[i-2];
    }

    cout << d[n] << "\n";
    
    return 0;
}

