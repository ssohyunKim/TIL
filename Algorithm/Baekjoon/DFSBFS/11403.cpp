#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int G[101][101];
int A[101][101];
queue<int> q;
bool visited[101][101];

void bfs(int start){
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(G[node][i]==1 && visited[start][i]==false){
                visited[start][i] = true;
                q.push(i);
                A[start][i] = 1;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n ;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> G[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        bfs(i);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
