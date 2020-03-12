#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b;
	int sub;
	int count = 0;
	scanf("%d %d", &a, &b);
	
	sub = abs(a-b);
	
	while(abs(sub)>=8){
		sub = abs(sub);
		sub -= 10;
		count ++;
	}
	while(abs(sub)>=4){
		sub = abs(sub);
		sub -= 5;
		count ++;
	}
	while(abs(sub)>0){
		sub = abs(sub);
		sub -= 1;
		count++;
	}
	
	printf("%d ", count);
	return 0;
}

