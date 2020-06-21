//12. 숫자의 총 개수(large: 제한시간 1초)
#include <stdio.h>

int main(){
    // d: 자릿수의 개수
    int n, sum = 0, c = 1, d = 9, ans = 0;
    scanf("%d", &n);

    while(sum+d<n){
        ans = ans + (c*d);
        sum = sum + d; 
        // 다음자리 숫자의 자리수와 개수
        c++;
        d = d * 10; 
    }

    ans = ans + ((n-sum) * c); 

    printf("%d\n", ans);
    return 0;
}