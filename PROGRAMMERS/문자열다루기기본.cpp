#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length()==4 || s.length()==6){
        // 숫자 체크
        for(int i=0; i<s.size(); i++){
            //if(s[i]>='0'&& s[i]<='9')
            if(isdigit(s[i])){
                continue;
            }else{
                answer = false;
                break;
            }
        }
    }else{
        answer = false;
    }
    return answer;
}