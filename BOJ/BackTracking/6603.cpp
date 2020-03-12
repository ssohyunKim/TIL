#include <iostream>

#define MAX 6
using namespace std;

int check[MAX];
int arr[13];
int n;
void DFS(int index, int cnt){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            cout << check[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=index; i<n; i++){
        check[cnt] = arr[i];
        DFS(i+1, cnt+1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        cin >> n;
        
        if(n==0){
            break;
        }
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        DFS(0, 0);
        cout << "\n";
    }
    return 0;
}
