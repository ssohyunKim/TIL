#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int main(void){
    int n,k;
    queue<int> q;

    cin >> n >> k;
   
    cout << "<";
    
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
    }
    cout << q.front() << ">" << endl;
    return 0;
}