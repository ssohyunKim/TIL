#include <iostream>

using namespace std;
long long p[101];
int t,n;
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    p[0]=0;
    p[1]=1;
    p[2]=1;
    p[3]=1;
    p[4]=2;
    p[5]=2;
    
    for(int i=6; i<=100; i++){
        p[i] = p[i-1] + p[i-5]; //점화식
    }
    
    cin >> n;
    
    while(n--){
        cin >> t;
        cout << p[t] << "\n";
    }
    return 0;
}

