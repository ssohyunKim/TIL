#include <iostream>
#include <vector>
using namespace std;

// 1. 총감독관은 1명
// 2. 부감독관은 (학생수 - 총감독관)

int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long int ans = 0;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int b, c;
    cin >> b >> c;

    for(int i=0; i<n; i++){
        ans += 1; // 총감독관은 1명 
        a[i] = a[i] - b;
        
        if(a[i] > 0){
            if(a[i]%c == 0){
                ans += a[i]/c;
            }else{
                ans += a[i]/c + 1;
            }
        }
        
    }

    cout << ans << "\n";

    return 0;
}