#include <iostream>
//³ª¸ÓÁö 
using namespace std;

int main(){
   int A;
   int B;
   int C;
   
   cin >> A;
   cin >> B;
   cin >> C;
    
   cout << (A+B)%C << endl;
   cout << (A%C + B%C)%C << endl;
   cout << (A*B)%C << endl;
   cout << (A%C*B%C)%C << endl;
   
   return 0;
}
