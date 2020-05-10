//5. 나이 계산(문자열 컨트롤)
//ascii 'A'(65) ~ 'Z'(90) 'a'(97)~'z'(122) '0'(48)~'9'(57)
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    int year, age;
    char gender;
    char a[20];

    scanf("%s", &a);

    if(a[7] == '1' || a[7] == '2') year = 1900 +((a[0]-48)*10 + (a[1]-48));
    else year = 2000 + ((a[0]-48)*10 + (a[1]-48));
    
    age = 2019 - year + 1;
    printf("%d ", age);

    if(a[7] == '1' || a[7] == '3'){
        gender = 'M' ;
    }else{
        gender = 'W';
    }
    
    printf("%c\n", gender);

    return 0;
}
