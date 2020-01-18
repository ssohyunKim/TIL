#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main(void){
   int k; //정수 k
   int sum = 0;
   stack<int> a;

   cin >> k;

   for(int i=0; i<k; i++){
      int n;
      cin >> n;
      
      if(n!=0){
         a.push(n);
      }else if(n==0){
         a.pop(); 
      }
   }

   for(int i=0; !a.empty(); i++){
      sum += a.top();
      a.pop();
   }
   
   cout << sum << endl;
}
   