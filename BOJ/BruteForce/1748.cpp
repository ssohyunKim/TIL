#include <iostream>
#include <cmath>

using namespace std;

int n;

// (백준 풀이)
// 수가 작다면 -> 정수를 문자열로 바꾼다음(to_string) 더하면서 길이를 재면된다.
// 여기서는 수가 매우 크다. -> 수의 자리수별로 나누어서 문제를 해결할 수 있다.
// 1~9 = (9-1+1) * 1
// 10~99 = (99-10+1) * 2
// 100~999 = (999-100+1)* 2

// 자리수의 합을 구하는 문제
// 1. 반복문 1부터 n까지
// 2. (log10(n) + 1 )이 자리수 
// 3. cnt 증가

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int cnt = 0;

//     cin >> n;

//     for(int i=1; i<=n; i++){
//         cnt += log10(i) + 1;
//     }

//     cout << cnt <<"\n";
//     return 0;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    long long ans = 0;
    // 1~9 = (9-1+1) * 1
    // 10~99 = (99-10+1) * 2
    // 100~999 = (999-100+1)* 2

    int len = 1;
    for(int i=1; i<=n; i*=10){
        int end = i * 10 - 1;
        if(end > n){
            end = n;
        }
        ans += (long long)(end - i + 1) * len;
        len++;
    }

    cout << ans << "\n";

    return 0;
}

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     long long ans = 0;
//     for (int start=1, len=1; start<=n; start*=10, len++) {
//         int end = start*10-1;
//         if (end > n) {
//             end = n;
//         }
//         ans += (long long)(end - start + 1) * len;
//     }
//     cout << ans << '\n';
//     return 0;
// }