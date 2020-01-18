#include <stdio.h>
#include <iostream>

using namespace std;

string check(string s) {
    int count = 0;
    for (int i=0; i<s.size(); i++){
        if(s[i] == '('){
            count++;
        }else{
            count--;
        }
    }
    if(count==0){
        return "YES";
    }else {
        return "NO";
    }
}
int main(void){
    int t;
    cin >> t;

    for(int i=t; i>0; i--){
        string s;
        cin >> s;
        cout << check(s) << endl;
    }
}