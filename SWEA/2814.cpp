//2814. 최장 경로
#include<iostream>
#include <cstring>

using namespace std;

int N, M, answer=1;
int graph[11][21];
bool visited[11];

void findPath(int idx, int cnt, int size){
    if(answer < cnt) answer = cnt;
    for(int i=1; i<=size; i++){
        if(graph[idx][i]==1 && graph[i][idx]==1 && !visited[i]){
            visited[i] = true;
            findPath(i, cnt+1, size);
            visited[i] = false;
        }
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		cin>>N>>M;

        // 초기화!! 
        memset(graph, 0, sizeof(graph));
        answer = 1;

        for(int i=0; i<M; i++){
            int x, y;
            cin>>x>>y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        for(int i=1; i<=N; i++){
            visited[i] = true;
            findPath(i, 1, N);
            visited[i] = false;
        }

        cout<<"#"<<test_case<<" "<<answer<<"\n";
	}
	return 0;
}