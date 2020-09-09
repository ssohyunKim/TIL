//1010. 다리 놓기
#include <iostream>

using namespace std;

int T, N, M;
long double f[31];
//long long 으로 풀기 n+1Ck+1 = nCk + nCk+1 
long long combination(int M, int N){
    if(M==N) return 1;
    if(N==1) return M;
    return combination(M-1, N-1) + combination(M-1, N);
}
int main(){

    f[0]=1;
    f[1]=1;
    for(int i=2; i<31; i++){
        f[i] = f[i-1] * i;
    }

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> M;
        
        cout << combination(M, N) << "\n";
    }
    
    return 0;
}