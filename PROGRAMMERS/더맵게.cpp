//더맵게
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > pq;
    
    //for(int e: scoville) pq.push(e);
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K) {
        // 스코빌 지수를 K 이상으로 만들 수 없는 경우 -1 리턴
        if(pq.size()==1) return -1;
            
        int min1 = pq.top();  
        pq.pop();
        
        int min2 = pq.top();  
        pq.pop();
        
        int mix_scoville = min1 + (min2 *2);
        pq.push(mix_scoville);
        
        answer++;
    }
    
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    cout << solution(scoville, 7) << "\n";

    return 0;
}