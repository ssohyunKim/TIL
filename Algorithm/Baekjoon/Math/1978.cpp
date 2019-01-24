#include <iostream>
//¼Ò¼ö 
using namespace std;
int n, array[100], count;
bool prime(int n);	

int main(){
	count = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> array[i];
	
		if(prime(array[i])==true){
			count +=1;
		}
	}
	
	cout << count;
	
	return 0;
}
bool prime(int n){
	if(n<2){
		return false;
	} 
	for(int i=2; i*i <=n; i++ ){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
