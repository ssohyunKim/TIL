#include <iostream>
//�ִ����� 
using namespace std;
int gcd(int x, int y);

int main(void){
	int a;
	int b;
	
	cin >> a;
	cin >> b;
		
	cout << gcd(a,b) << endl;
	cout << (a*b)/gcd(a,b) << endl;
	
	return 0;
}
int gcd(int x, int y){
	if(y == 0){
		return x;
	}else {
		return gcd(y, x%y);
	}
}

