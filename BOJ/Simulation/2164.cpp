#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> a(N);
    
    deque<int> dq;
    
    for(int i=0; i<N; i++){
        dq.push_back(i+1);
    }
    
    for(int i=0; i<N-1; i=i+2){
        while(dq.size()>1){
            //first = dq.front();
            //cout << first <<"\n";
            dq.pop_front(); // 1. 맨 앞의 원소 pop
            
            int second = dq.front(); // 2. 다음으로 오는 앞의 원소를 pop하고, 맨 뒤에 push
            //cout << second <<"\n";
            dq.pop_front();
            dq.push_back(second);
        }
    }
    cout << dq.front();
    return 0;
}
//1 2 3 4
//2 3 4
//3 4 2
//4 2
//2 4
//4

