#include <iostream>

using namespace std;

int n;
int num[101];
long long d[101][21];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
 
    d[0][num[0]] = 1;
 
    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (d[i][j] != 0) {
                if (j + num[i] <= 20) {
                    d[i][j + num[i]] += d[i-1][j];
                }
                if (j - num[i] >= 0) {
                    d[i][j - num[i]] += d[i-1][j];
                }
            }
        }
    }
 
    cout << d[n-2][num[n-1]] << "\n";
   
    return 0;
}
