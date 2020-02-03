#include <iostream>
using namespace std;
#define MAX 100000

int arr[MAX];
int n,m;

bool check(int a){
    for(int i=0; i<n; i++){
        if(arr[i]==a){
            return true;
        }else{
            continue;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        if(check(num)){
            cout << 1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }
    return 0;
}
