#include <iostream>
//GCD
using namespace std;
int gcd(int a, int b);
int t, n, array[1000001], sum[101];
// int array[1000001] = {0,};
int main()
{
	cin >> t;
	
	for(int k = 0; k < t; k++){
		
		sum[k]=0;
		
		cin >> n;
		
		for(int i = 0; i < n ; i ++){
			cin >> array[i];
		}
		
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n ; j++){
				//cout << array[i] << "," << array[j] << endl;
				//cout << gcd(array[i], array[j]) << endl;
				sum[k] += gcd(array[i], array[j]);
			}	
		}
	}   
	for(int i = 0; i < t; i++){
		cout << sum[i] << endl;
	} 
	return 0;
}
int gcd(int a, int b){
	if(b==0){
		return a;
	} else {
		return gcd(b, a%b);
	}
}
