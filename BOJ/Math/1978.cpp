#include <iostream>
//�Ҽ� 
using namespace std;
int n, arr[100], cnt;
bool prime(int n);	

int main(){
	cnt = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	
		if(prime(arr[i])==true){
			cnt +=1;
		}
	}
	
	cout << cnt;
	
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
