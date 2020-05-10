//모두의 약수
//n이 30,000이상이면 타임아웃(제한시간:1초)
//입력: 8
//출력: 1 2 2 3 2 4 2 4
#include <stdio.h>

int cnt[50001];
int main(){
    int n;

    scanf("%d", &n);

    // timeout
    // for(int i=1; i<=n; i++){
    //     int cnt = 0;
    //     for(int j=1; j<=i; j++){
    //         if(i%j == 0){
    //             cnt ++;
    //         }
    //     }
    //     printf("%d ", cnt);
    // }

    //n이 클수록 j값이 훅훅 증가
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j=j+i){
            cnt[j]++;
        }
    }

    for(int i=1; i<=n; i++){
        printf("%d ", cnt[i]);
    }

    return 0;
}