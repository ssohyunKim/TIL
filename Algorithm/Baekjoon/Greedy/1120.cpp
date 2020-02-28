#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
int sum=9999999;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;

    for(int j=0; j<=b.length()-a.length(); j++){
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i+j])
                cnt ++;
        }
        sum = min(cnt, sum);
    }
    cout << sum << "\n";
    
    return 0;
}
