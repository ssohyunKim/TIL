// 피보나치 수
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long int f[100001];
int solution(int n) {
    int answer = 0;
    f[0] = 0;
    f[1] = 1;
    
    for(int i=2; i<=n; i++){
        f[i] = (f[i-1] + f[i-2])%1234567; 
    }
    
    answer=f[n];
    
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    cout << solution(n);

    return 0;
}