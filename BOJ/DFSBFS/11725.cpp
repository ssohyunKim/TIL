//11725. 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

bool visited[100001];
int parent[100001];
vector<int> v[100001];

void dfs(int currentNode){
    visited[currentNode] = true;

    for(int i=0; i<v[currentNode].size(); i++){
        int nextNode = v[currentNode][i];
        
        if(!visited[nextNode]){
            parent[nextNode] = currentNode;
            dfs(nextNode);
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int firstNode, secondNode;
        cin >> firstNode >>  secondNode;

        v[firstNode].push_back(secondNode);
        v[secondNode].push_back(firstNode);
    }

    dfs(1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}