//11728. 배열 합치기
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    
    int a[N];
    int b[M];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    for(int i=0; i<M; i++){
        cin >> b[i];
    }

    int array[N+M];
    int aindex=0, bindex=0;
    for(int i=0; i<N+M; i++){
        if(aindex >= N){
            array[i] = b[bindex];
            bindex++;
            continue;
        }
        if(bindex >= M){
            array[i] = a[aindex];
            aindex++;
            continue;
        }
        if(a[aindex] < b[bindex]){
            array[i] = a[aindex];
            aindex++;
        }else{
            array[i] = b[bindex];
            bindex++;
        }
    }

    for(int i=0; i<N+M; i++){
        cout << array[i] << " ";
    }

    return 0;
}