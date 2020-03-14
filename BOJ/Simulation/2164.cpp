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
    
    queue<int> q;
    
    for(int i=0; i<N; i++){
        q.push(i+1);
    }
    
    for(int i=0; i<N-1; i=i+2){
        while(q.size()>1){
            q.pop(); // 1. 맨 앞의 원소 pop
            
            int element = q.front(); // 2. 다음으로 오는 앞의 원소를 pop하고, 맨 뒤에 push
            q.pop();
            q.push(element);
        }
    }
    cout << q.front();
    return 0;
}