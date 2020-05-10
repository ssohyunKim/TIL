//3. 진약수의 합
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int ans = 0;
    cin >> n;

    for(int i=1; i<n; i++){
        if(n%i == 0){
            cout << i << "+";
            ans += i;
        }
    }
    cout << n << "=";

    cout << ans << "\n";

    return 0;
}