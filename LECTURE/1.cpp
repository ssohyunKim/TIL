//1. 1부터 N까지 M의 배수합
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    int ans = 0;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        if(i%m == 0){
            ans += i;
        }
    }

    cout << ans << "\n";
    return 0;
}