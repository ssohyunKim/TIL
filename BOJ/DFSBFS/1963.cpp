#include <iostream>

using namespace std;

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