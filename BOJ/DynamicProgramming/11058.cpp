#include <iostream>
#include <algorithm>

using namespace std;

// 1. 화면에 A를 출력한다.
// 2. Ctrl-A: 화면을 전체 선택한다
// 3. Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
// 4. Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.

int n;
int dp[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[1] = 1;
    for(int i=2; i<=100; ++i){
        dp[i] = dp[i-1]+1;
        for(int j=1; j<i-2; ++j)
            dp[i] = max(dp[i], dp[j] * (i-j-1));
    }

    cout << dp[n] << "\n";
	return 0;
}