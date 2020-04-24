#include <iostream>

#define MAX 9
using namespace std;

int num[MAX];
bool visited[MAX];
int n, m;

// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.

void dfs(int cnt){
    //cout << "debug" << " dfs(" << cnt << ") \n";
    if(cnt == m){
        // 출력
        for(int i = 0; i < m; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        num[cnt] = i;
        dfs(cnt+1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    dfs(0);
    
    return 0;
}
