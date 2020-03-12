#include <iostream>
#include <string>
using namespace std;
int cnt=0;

bool check(string s){
    int size = s.size();
    for(int i=0; i<size-2; i++){
        if(s[i]!= s[i+1]){
             for(int j=i+2; j<size; j++){
                 if(s[i]==s[j]){
                     return false;
                 }
             }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    string str;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> str;
        if(check(str)){
            cnt++;
        }
    }
    
    cout << cnt ;
    
    return 0;
}
