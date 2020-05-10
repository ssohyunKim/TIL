//7. 영어 단어 복구(문자열 컨트롤)
//gets 함수가 문자열이라고 감지하는 기준은 개행(\n). 들어온 문자열에 대해 '\0'을 붙여준다.
#include <stdio.h>

int main(){
    char a[101];
    char b[101];

    gets(a);

    int p = 0;
    for(int i=0; a[i]!='\0'; i++){
        if(a[i]!=' '){
            if(a[i]>=65 && a[i]<=90){
                b[p++] = a[i] + 32;
            }else{
                b[p++] = a[i];
            }
        }
    }
    b[p] = '\0';

    printf("%s\n", b);
    return 0;
}