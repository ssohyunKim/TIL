//2003. 수들의 합2
#include <iostream>

using namespace std;

int N, M;
int array[10001];
int answer = 0;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> array[i];
    }

    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=i; j<N; j++){
            sum += array[j];
            if(sum > M) break;
            if(sum == M) answer ++;
        }
    }

    cout << answer << "\n";

    return 0;
}