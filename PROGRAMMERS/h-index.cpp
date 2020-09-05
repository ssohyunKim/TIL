#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std; 
    
int solution(vector<int> citations) {
    int answer = 0;
    
    priority_queue<int, vector<int>, less<int> > pq;
    
    for(int i=0; i<citations.size(); i++){
        pq.push(citations[i]);
    }

    int current;
    for(int i=1; i<=citations.size(); i++){
        current = pq.top();
        // h-index값이 배열에 있는 원소 값인 경우
        if(current == i){
            return current;
        }
        // h-index값이 배열의 값이 아닌 경우
        else if(current < i){
            return i-1;
        }
        pq.pop();
    }
    //모든 논문의 인용 횟수가 논문의 갯수보다 많을 때는 논문의 갯수 리턴
    if(current >= citations.size()){
        return citations.size();
    }
    return answer;
}