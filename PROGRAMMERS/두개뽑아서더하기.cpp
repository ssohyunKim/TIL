//두 개 뽑아서 더하기
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s; 
    
    for(int i=0; i<numbers.size(); i++){
        for(int j=0; j<numbers.size(); j++){
            if(i==j) continue;
            int hap = numbers[i] + numbers[j];
            s.insert(hap);
        }
    }
    
    set<int>::iterator iter;
    for(iter=s.begin(); iter!=s.end(); iter++){
        int su = *iter;
        answer.push_back(su);
    }
    return answer;
}