#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string s;
    stack<int> a;
    int sum=0;

    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            a.push(i); 
        }else{
            if(i-a.top()==1){
                a.pop();
                sum += a.size();
            }else{
                a.pop();
                sum += 1;
            }
        }
    }
    
    cout << sum << endl;
}