//자릿수의 합
//입력: 5
//출력: 125 15232 79 1325 97
#include <iostream>

using namespace std;

int digit_sum(int x){
    int tmp, sum = 0;
    while(x>0){
        tmp = x%10;
        sum += tmp;
        x /= 10;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, num, sum, ans;
    int max = -2147000000;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num;
        sum = digit_sum(num);
        if(sum > max){
            max = sum;
            ans = num;
        }
        //같은 값인 경우 가장 큰 값을 출력한다. 
        else if(sum == max){
            if(num > ans) ans = num;
        }
    }
    cout << ans << "\n";
    return 0;
}