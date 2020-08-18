#include <string>
#include <cstring>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > computers, bool visited[], int current){
    visited[current] = true;

    for(int i=0; i<computers.size(); i++){
        if(!visited[i] && computers[current][i]==1){
            dfs(computers, visited, i);
        }
    }
}
int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    bool visited[n];
    
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<n; i++){
        if(!visited[i]){
            answer ++;
            dfs(computers, visited, i);
        } 
        visited[i] = false;
    }

    return answer;
}  