#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_hap = 0;
    queue<int> q;
   
    for(int i=0; i<truck_weights.size(); i++){
        while(true){
            if(q.empty()){
                q.push(truck_weights[i]);
                weight_hap += truck_weights[i];
                answer++; 
                break;
            }else if(q.size()==bridge_length){
                weight_hap -= q.front();
                q.pop();
            }else{
                if(weight_hap + truck_weights[i] <= weight){
                    q.push(truck_weights[i]);
                    weight_hap += truck_weights[i];
                    answer++;
                    break;
                }else{
                    q.push(0);
                    answer++;
                }
            }
        }
    }
    return answer+bridge_length;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);

    cout << solution(2, 10, truck_weights) << "\n";

    return 0;
}