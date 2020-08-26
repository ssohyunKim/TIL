#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 접두어가 있으면 false, 접두어가 없으면 true

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(string cand : phone_book){
        int size = cand.size();
        
        for(string phone : phone_book){
            if(size > phone.size() || cand == phone) continue;
            // 접두어 크기만큼 잘라서 같은지 비교
            string number = phone.substr(0, size);
            if(cand.compare(number) == 0){
                return false;
            }
        }
    }
    return answer;
}