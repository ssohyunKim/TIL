#include <iostream>
#include <algorithm>

using namespace std;

// 1. 화면에 A를 출력한다.
// 2. Ctrl-A: 화면을 전체 선택한다
// 3. Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
// 4. Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.

int n;
long long int dp[101]; // dp[i]:버튼을 총 i번 눌러서 화면에 출력된 개수의 최댓값
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;

    for(int i=7; i<=n; ++i){
        for(int j=3; i-j>0; ++j)
            dp[i] = max(dp[i], (j-1) * dp[i-j]);
    }

    cout << dp[n] << "\n";
	return 0;
}