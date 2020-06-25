#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    
    for(string name : participant){
        map[name] ++;
    }
    for(string name : completion){
        map[name] --;
    }
    for(auto elem : participant){
        if(map[elem] > 0 ){
            answer = elem;
        }
    }
    return answer;
}