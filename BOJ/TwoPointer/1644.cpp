//1644. 소수의 연속합
#include <iostream>
#include <vector>

using namespace std;

int num[4000001];
int main(){
    int N;
    cin >> N;

    //약수의 개수
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j=j+i){
            num[j]++;
        }
    }

    //소수 구하기
    vector<int> sosu;
    for(int i=1; i<=N; i++){
        if(num[i]==2)
            sosu.push_back(i);
    }

    int sum = 0, left = 0, right = 0, answer = 0;
    while(true){
        if(sum < N){
            if(right == sosu.size()) break;
            sum += sosu[right];
            right++;
        }else if(sum >= N){
            if(sum == N) answer++;
            sum -= sosu[left];
            left++;
        }
    }

    cout << answer << "\n";
    return 0;
}