#include <stdio.h>

int main(void){

	int i,j, min, temp, index;
	int array[3];
	
	for(i = 0; i < 3; i++){
		scanf("%d", &array[i]);
	}
	for(i = 0; i < 3; i++){
		min = array[i];
		for(j = i; j < 3 ; j++){
			if(min > array[j]){
				min = array[j];
				index = j;
			}
			
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
		
	}
	for(i=0; i < 3; i++){
		printf("%d ", array[i]);
	}
	return 0;	
}
