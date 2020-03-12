#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    queue <int> q;
    string str;
    int result;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> str;
        if(str == "push"){
            cin >>  m;
            q.push(m);
        }else if(str == "front"){
            if(!q.empty()){
                cout << q.front() <<"\n";
            }else{
                cout << -1 <<"\n";
            }
        }else if(str == "back"){
            if(q.size() == 0){
                cout << -1 <<"\n";
            }else{
                cout << q.back() <<"\n";
            }
        }else if(str == "size"){
            cout << q.size() << "\n";
        }else if(str == "empty"){
            if(q.empty()){
                result = 1;
            }else{
                result = 0;
            }
            cout << result << "\n";
        }else if(str == "pop"){
            if(!q.empty()){
                result = q.front();
                q.pop();
            }else{
                result = -1;
            }
            cout << result << "\n";
        }
    }
    return 0;
}
