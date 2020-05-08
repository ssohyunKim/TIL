#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 숫자를 이진수로 만든다.
// 2. 비밀지도 1,2 만들기
// 3. 하나라도 벽이면 벽, 모두 공백이면 공백(OR)
// 4. 전체지도를 배열로 출력한다.

vector<string> ret;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    //이진수로 만들기 -> 비트연산 | 를 이용하자.
    for(int i=0; i<n; i++){
        string s = "";
        int num = arr1[i] | arr2[i];
        for(int j=0; j<n; j++){
            if(num%2==0){
                s+=" ";
            }else{
                s+="#";
            }
            //시프트 연산 오른쪽으로 1비트씩 이동
            num = num >> 1;
        }
        //뒤집기
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> arr1;
    vector<int> arr2;

    n = 5;

    arr1 = {9, 20, 28, 18, 11};
    
    arr2 = {30, 1, 21, 17, 28};
    
    ret = solution(n, arr1, arr2);
    
    for(int i=0; n; i++){
        cout << ret[i] << " ";
    }

    return 0;
}