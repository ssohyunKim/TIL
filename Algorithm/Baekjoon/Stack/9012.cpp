#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

bool check(string s) {
    stack<char> a;

    for (int i=0; i<s.size(); i++){
        if(s[i] == '('){
            a.push(s[i]);
        }else{
            if(!a.empty()){
                a.pop();
            }else{ 
                return false;
            }
        }
    }
   return a.empty;
}
int main(void){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        
        if(check(s)){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}