//1806. 부분합
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
const int INF = 999999999;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int i=0, j=0, answer = INF, sum = 0;
    while(true){
        if(sum < S){
            if(j == N) break;
            sum += arr[j];
            j++;
        }else{
            answer = min(answer, j-i);
            sum -= arr[i];
            i++;
        }
    }

    if(answer == INF)
        cout << 0 << "\n";
    else 
        cout << answer << "\n";

    return 0;
}