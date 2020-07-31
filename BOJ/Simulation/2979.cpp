// 2979. 트럭주차
#include <iostream>
#include <vector>

using namespace std;
// 트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 
// 두 대를 주차할 때는 1분에 한 대당 B원, 
// 세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.
int A, B, C;
int check[101];
int ans=0;
int t1, t2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;
    for(int i=0; i<3; i++){
        cin >> t1 >> t2;
        for(int j=t1; j<t2; j++){
            check[j]+=1;
        }
    }
    for(int i=0; i<100; i++){
        if(check[i]==3){
            ans+=C*3;
        }else if(check[i]==2){
            ans+=B*2;
        }else if(check[i]==1){
            ans+=A;
        }
    }
    cout << ans << "\n";
    return 0;
}