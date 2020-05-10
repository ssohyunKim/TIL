//6. 숫자만 추출(문자열 컨트롤: 아마존 인터뷰)
//입력: g0en2Ts8eSoft
//출력: 28, 6
#include <stdio.h>

int main(){
    char a[100];
    int ans = 0;
    int cnt = 0;

    scanf("%s", &a);
    for(int i=0; a[i]!= '\0'; i++){
        if(a[i] >= 48 && a[i] <= 57)
            ans = ans*10 + (a[i]-48);
    }

    printf("%d\n", ans);
    for(int i=1; i<=ans; i++){
        if(ans%i == 0){
            cnt ++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
