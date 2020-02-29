#include <iostream>

using namespace std;
int n, p;
int computer[101][101];
int visited[101]; //방문했는지 안했는지 배열
int cnt=0;

void DFS(int start, int pair){
    visited[start]=1;
    cnt ++;
    
    for(int i=0; i<n+1; i++){
        if(computer[start][i]==1 && visited[i]==0){ //연결되어 있고 방문안한 노드면
            DFS(i, pair); //해당노드를 시작노드로 하여 탐색
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n; // 컴퓨터 수
    cin >> p; // 컴퓨터 쌍의 수
    
    for(int i=0; i<p; i++){
        int a,b;
        cin >> a >> b;
        computer[a][b] = 1;
        computer[b][a] = 1;
    }
    
    DFS(1, p);
    
    cout << cnt-1 <<"\n";
    return 0;
}

