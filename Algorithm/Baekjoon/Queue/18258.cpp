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
    char s[7];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s[1]=='u'){
            cin >> num;
            q.push(num);
        }else if(s[1]=='o'){
            if(!q.empty()){
                cout << q.front() <<"\n";
                q.pop();
            }else{
                cout << -1 << "\n";
            }
        }else if(s[1]=='i'){
            cout << q.size() << "\n";
        }else if(s[1]=='m'){
            cout << (q.empty() ? 1:0) << "\n";
        }else if(s[1]=='r'){
            cout << (q.empty() ? -1:q.front()) <<"\n";
        }else if(s[1]=='a'){
            cout << (q.empty() ? -1:q.back()) << "\n";
        }
    }
    return 0;
}
