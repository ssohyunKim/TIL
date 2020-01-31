#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    queue<int> q;
    int n;
    int num;

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s=="push"){
            cin >> num;
            q.push(num);
        }else if(s=="pop"){
            if(!q.empty()){
                cout << q.front();
                q.pop();
            }else{
                cout << -1;
            }
            cout << "\n";
        }else if(s=="size"){
            cout << q.size() <<"\n";
        }else if(s=="empty"){
            if(q.empty()){
                cout << 1;
            }else{
                cout << 0;
            }
            cout << "\n";
        }else if(s=="front"){
            if(!q.empty()){
                cout << q.front();
            }else{
                cout << -1;
            }
            cout << "\n";
        }else if(s=="back"){
            if(!q.empty()){
                cout << q.back();
            }else{
                cout << -1;
            }
            cout << "\n";
        }
    }
    return 0;
}
