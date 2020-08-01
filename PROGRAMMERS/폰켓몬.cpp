#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
bool check[200001];

int solution(vector<int> nums)
{
    int answer = 0;

    int size = nums.size();
    for(int i=0; i<size; i++){
        if(check[nums[i]] == false){
            check[nums[i]] = true;
            answer++;

            if(answer == size/2) break;
        }
    }
   
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    cout << solution(nums) <<"\n";

    return 0;
}