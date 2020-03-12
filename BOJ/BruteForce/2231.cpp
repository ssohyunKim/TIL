#include <iostream>
using namespace std;

int s,r;
int n;
bool flag = true;
int divide(int m, int sum){
    s = m/10;
    r = m%10;

    if(s!=0){
        sum += r;
        return divide(s, sum);
    }else{
        sum += r;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int result;

    for(int i=0; i<n; i++){
        result = divide(i, i);
    
        if(result == n){
            cout << i <<"\n";
            flag = false;
            break;
        }
    }
    
    if(flag){
        cout << 0 <<"\n";
    }

    return 0;
}
