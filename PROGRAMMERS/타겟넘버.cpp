#include <string>
#include <vector>

using namespace std;
//dfs
//더하거나 빼서 타겟 넘버 만들기
//갯수 세기
int ans = 0;
void makeNumber(vector<int> numbers, int target, int cnt, int result){
    if(cnt == numbers.size()){
        if(result == target){
            ans ++;
        }
        return;
    }
    //더하기
    makeNumber(numbers, target, cnt+1, result+numbers[cnt]);
    //빼기
    makeNumber(numbers, target, cnt+1, result-numbers[cnt]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    makeNumber(numbers, target, 0, 0);
    
    answer = ans;
    return answer;
}