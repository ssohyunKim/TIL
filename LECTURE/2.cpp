//2. 자연수의 합
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int ans = 0;
    cin >> a >> b;

    for(int i=a; i<b; i++){
        ans += i;
        cout << i << "+";
    }
    cout << b << "=";
    ans += b;
    cout << ans << "\n";

    return 0;
}