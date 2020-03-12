#include <iostream>

using namespace std;

int n,s;
int arr[21];
int cnt=0;
void find(int index, int sum){
    if(n==index){
        if(sum==s){
            cnt ++;
        }
        return;
    }
    find(index+1, sum+arr[index]); 
    find(index+1, sum);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    find(0, 0);
    if(s==0){ //s가 0일 경우, 공집합에 대해 cnt값이 1이 추가되기때문에 빼줘야한다.
        cnt += -1;
    }
    cout << cnt << "\n";
    return 0;
}

