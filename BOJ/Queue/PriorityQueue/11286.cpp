#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>

#define MAX 10000
using namespace std;
int n, x;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<pair<int, int> > pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> x;
        if(x==0){
            if(pq.empty()){ //비었으면 0 출력
                cout << 0 << "\n";
            }else{
                cout << -pq.top().second <<"\n"; // pair이므로 두번째값이 찾고자하는
                pq.pop();
            }
        }else{
            pq.push({-abs(x), -x});
        }
    }
    return 0;
}

