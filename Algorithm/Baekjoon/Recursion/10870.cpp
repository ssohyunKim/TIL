#include <stdio.h>
#include <iostream>

using namespace std;
int fibonacci(int n);

int main(void){
	int N;	
	cin >> N;
	
	cout << fibonacci(N) << endl;
	
	return 0;
}
int fibonacci(int n){
	if(n<=1) { 
		return n;
	}else {
		return fibonacci(n-1) + fibonacci(n-2);	
	}
}

