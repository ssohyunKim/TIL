//4. 나이 차이
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt","rt",stdin);

    int n, a;
    int max = -2147000000;
    int min = 2147000000;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a;
        if(a>max) max = a;
        if(a<min) min = a;
    }

    cout << max-min <<"\n";

    return 0;
}