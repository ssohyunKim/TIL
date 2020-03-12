#include <iostream>
using namespace std;
#define MAX 8

int arr[MAX];
int n,m;
void DFS(int index, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=index; i<n; i++){
        arr[cnt] = i+1;
        DFS(i+1, cnt+1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    DFS(0, 0);
    
    return 0;
}
