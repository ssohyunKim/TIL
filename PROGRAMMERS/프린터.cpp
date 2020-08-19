//프린터
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> pq;
    queue<pair<int, int> > q;

    for(int i=0; i<priorities.size(); i++){
       q.push(make_pair(i, priorities[i]));
       pq.push(priorities[i]); 
    }

    while(!q.empty()){
        int index = q.front().first;
        int priority = q.front().second;
        q.pop();

        if(priority == pq.top()){
            pq.pop();
            answer += 1;

            if(index == location){
                break;
            }
        }else{
            q.push(make_pair(index, priority));
        }
    }
    return answer;
}
int main(){
    vector<int> priorities;

    priorities.push_back(2);
    priorities.push_back(1);
    priorities.push_back(3);
    priorities.push_back(2);

    cout << solution(priorities, 2) <<"\n";
    
    return 0;
}