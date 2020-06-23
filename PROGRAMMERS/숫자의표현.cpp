#include <string>
#include <vector>

using namespace std;

//1. 반복문 돌리면서 
//2. 연속되는 숫자 합이 15면 break
//3. 그 때 마다 answer 값 증가
//3. 15보다 커져도 break

int solution(int n) {
    int answer = 0;
    int sum = 0;

    for(int i=1; i<=n; i++){
        int val = i;
        sum = val;
        if(sum == n){
            answer ++;
            break;
        }
        for(int j=i+1; j<n; j++){
            sum += j;
            if(sum == n){
                answer ++;
                break;
            }else if(sum > n){
                break;
            }
        }
    }

    return answer;
}