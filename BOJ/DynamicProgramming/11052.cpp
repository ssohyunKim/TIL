#include <iostream>
#include <algorithm>

using namespace std;

int n;
int p[10001];
int d[1001];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            d[i] = max(d[i], d[i-j] + p[j]);
        }
    }

    cout << d[n] << "\n";
	return 0;
}