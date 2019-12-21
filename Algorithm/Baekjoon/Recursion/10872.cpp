#include <stdio.h>
#include <iostream>

using namespace std;
int factorial(int n);

int main(){
	int N;
	int result;
	
	cin >> N;
		
	cout << factorial(N) << endl;
	
	return 0;
}
int factorial(int n){
	
	if(n > 0){
		return n*factorial(n-1);
	}else{
		return 1;
	}
}
