#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,v;
vector<int> graph[1001];
queue<int> q;
bool visited[1001];
void dfs(int node){
    visited[node] = true;
    cout << node << ' ';
    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}
void bfs(int start){
    queue<int> q;
    memset(visited,false,sizeof(visited));
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> v;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);
    
    return 0;
}
