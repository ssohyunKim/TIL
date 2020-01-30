#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define MAX 9
using namespace std;

int arr[MAX];
bool select[MAX];
int n, m;

void DFS(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(select[i] == true){
            continue;
        }else{
            select[i] = true;
            arr[cnt] = i;
            DFS(cnt+1);
            select[i] = false;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
//    for(int i=0; i<n; i++){
//        arr[i] = i+1;
//    }
    
    DFS(0);
    
    return 0;
}