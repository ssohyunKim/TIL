//11. 숫자의 총 개수(small)
#include <stdio.h>

int main(){
    int n, tmp, ans=0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        //임시변수 필요
        tmp = i;
        while(tmp>0){
            tmp = tmp/10;
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}