//기능개발
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    queue<int> q;
    
    int size = progresses.size();
    for(int i=0; i<size; i++){
        int remain = 100 - progresses[i];
        int deploy_day = 0;
        if(remain % speeds[i] == 0){
            deploy_day = remain / speeds[i];
        }else{
            deploy_day = (remain / speeds[i]) + 1;
        }
        days.push_back(deploy_day);
    }
    
    q.push(days[0]);
    for(int i=1; i<days.size(); i++){
        if(q.front() >= days[i]){
            q.push(days[i]);
        }else{
            answer.push_back(q.size());
            while(!q.empty()) q.pop();
            q.push(days[i]);
        }
    }
    
    if(!q.empty()) answer.push_back(q.size());
    return answer;
}