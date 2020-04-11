#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//1. 실패율 계산
//2. 스테이지 번호 실패율 순으로 내림차순 정렬
bool compare(const pair<int, double> &a, const pair<int, double> & b){
    //두번째 수가 같다면
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > v;
    
    for(int i=1; i<=N; i++){
        int challenge = 0; //도전자 수
        int fail = 0;      //실패자 수
       
        for(int j=0; j<stages.size(); j++){   
            if(stages[j] >= i){
                challenge++;
            }
            if(stages[j] == i){
                fail++;
            }
        }
        
        if(challenge == 0){ //해당 스테이지에 간 사람이 아무도 없음
            v.push_back(make_pair(i, 0));
        }else{
            v.push_back(make_pair(i, (double)fail/challenge));
        }
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}