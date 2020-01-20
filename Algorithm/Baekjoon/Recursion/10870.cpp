#include <stdio.h>
#include <iostream>

int fibonacci(int n);
using namespace std;

int main(void){
    int n;
    
    cin >> n;
    
    cout << fibonacci(n) << endl;
    
    return 0;
}
int fibonacci(int n){
    if(n==0||n==1){
        return n;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
