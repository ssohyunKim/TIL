//구명보트
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int i=0, j=0;
    for(j=people.size()-1; j>i; j--){
        if(people[j]+people[i] <= limit){
            people.pop_back();
            i++;
            answer++;
        }else{
            people.pop_back();
            answer++;
        }
    }
    
    return answer;
}