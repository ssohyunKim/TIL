#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    // - : 백스페이스 커서의 앞에 문자가 존재하면 지움
    // < > : 커서를 왼쪽 또는 오른쪽으로 1칸 움직임
    // 커서의 위치가 마지막이 아니면, 문자를 입력하고 커서는 오른쪽으로 한칸 이동함
   
    int n;
    scanf("%d", &n);

    while(n--){
        char str[1000001];
        char temp[1000001];
        char pwd[1000001];

        scanf("%s", str);
        //str[1000000] = '\0';

        int j, k = 0;
        for(int i=0; str[i]; i++){
            if(str[i]=='-'){
                if(j>0) pwd[--j] = 0;
            }else if(str[i]=='<'){
                if(j>0) temp[k++] = pwd[--j];
            }else if(str[i]=='>'){
                if(k>0) pwd[j++] = temp[--k];
            }else{
                pwd[j++] = str[i];
            }
        }
        while(k--) pwd[j++] = temp[k];
        pwd[j]=0;
        printf("%s", pwd);
        printf("\n");
    }
    return 0;
}
