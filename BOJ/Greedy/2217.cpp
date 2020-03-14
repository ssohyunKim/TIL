#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N;
    cin >> N;
    
    int W[N];
    
    // 각 로프가 버틸 수 있는 최대 중량
    for(int i=0; i<N; i++){
        cin >> W[i];
    }
    
    sort(W, W+N, desc); // 내림차순으로 정렬
    
    int ans = 0;
    for(int i=0; i<N; i++){
        W[i] = W[i] * (i+1);
        if(ans < W[i]){
            ans = W[i];
        }
    }
    cout << ans << "\n";
    return 0;
}

