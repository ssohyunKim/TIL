//2003. 수들의 합2
#include <iostream>

using namespace std;

int N, M;
int arr[10001];
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    } 

    int i = 0, j = 0, sum = 0, answer = 0;
    while(true){
        if(sum < M){
            if(j == N+1) break;
            sum += arr[j];
            j++;
        }else if(sum >= M){
            if(sum == M) answer++;
            sum -= arr[i];
            i++;
        }
    }

    cout <<  answer << "\n";
    return 0;
}