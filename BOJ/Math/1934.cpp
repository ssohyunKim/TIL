#include <iostream>
//최소공배수 
using namespace std;
int gcd(int x, int y);

int main(){
	
	int n,a,b;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> a >> b;
		if(gcd(a,b) == 1){
			cout << a*b << endl;
		}else {
			cout << a*b/gcd(a,b) << endl;
		}
	}
	
	return 0;
}
int gcd(int x,int y){
	if(y==0){
		return x;
	}else {
		return gcd(y,x%y);
	}
}
