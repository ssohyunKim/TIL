//11724. 연결 요소의 개수
//연결 요소란? 무방향 그래프에서 서로 다른 두 정점이 경로로 연결되어 있으면서 상위 그래프의 추가 정점이 없는 부분 그래프를 의미
//<조건>
//1. 연결 요소에 속한 모든 정점을 연결하는 경로가 있어야 한다.
//2. 또 다른 연결 요소에 속한 정점과 연결하는 경로가 있으면 안된다.
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[1001];
bool visited[1001];

void dfs(int node){
    visited[node] = true;

    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if(visited[next] == false){
            dfs(next);
        }
    }

}
int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int components = 0;
    for(int i=1; i<=N; i++){        //모든 인접 리스트를 순회하면서
        if(visited[i] == false){    //방문하지 않은 노드가 있다면
            dfs(i);                 //하나의 연결 요소 모두 방문
            components+=1;           //연결요소의 수 증가
        }
    }

    cout << components << "\n";

    return 0;
}