#include <iostream>
#include <queue>

#define MAX 100000;
using namespace std;

struct INFO{
    int location, time;
};
int n, k ;
bool visited[MAX];
INFO info;

void bfs(int n, int k){
    queue<INFO> q;
    q.push(info);
    visited[n] = true;

    while(!q.empty){
        INFO cur;
        visited[cur.location] = true;
        q.push(info);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    cout << 

    return 0;
}