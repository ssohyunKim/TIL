#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    
    for(int i=0; i<clothes.size(); i++){
        string key = clothes[i][1];
        string value = clothes[i][0];
        if(map.end() == map.find(key)){
            map.insert(make_pair(key,1));
        }else{
            map[key]++;
        }
    }
    unordered_map<string, int>::iterator iter;
    
    for(iter = map.begin(); iter != map.end(); iter++){
        answer = answer + (iter->second * answer);
    }
    
    return answer-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<string> > clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };

    cout << solution(clothes);
}
