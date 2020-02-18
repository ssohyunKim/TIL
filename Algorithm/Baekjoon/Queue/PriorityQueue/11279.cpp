#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int> pq;
    int n,x;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x>0){
            pq.push(x);
        }else if(x==0){
            if(pq.empty()){// 배열이 비어있는 경우
                cout << 0 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}

