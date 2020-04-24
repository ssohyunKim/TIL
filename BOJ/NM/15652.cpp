#include <iostream>

using namespace std;

int n, m;
int num[10];
// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
// 고른 수열은 비내림차순이어야 한다. 
void dfs(int x, int cnt){
    //cout << "debug" << x << " " << cnt << "\n";

    if(cnt == m){
        //출력
        for(int i = 0; i < m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = x; i <= n; i++){
        
        num[cnt] = i;
        dfs(i, cnt+1);
    }    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    dfs(1, 0);

    return 0;
}