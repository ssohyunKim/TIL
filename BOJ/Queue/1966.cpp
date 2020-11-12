//1966. 프린터큐
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 오름차순 정렬하고 싶을때(greater 사용도 가능)
// struct compare{
//     bool operator()(int a, int b){
//         return a < b;
//     }
// }
int main(){
    int test_case;
    cin >> test_case;
    vector<int> v;
    for(int i=0; i<test_case; i++){
        int N, M;
        cin >> N >> M;

        queue<pair<int, int> >  q;
        priority_queue<int, vector<int> > pq; //자료형 int, 컨테이너 vector, 기본값은 내림차순

        for(int j=0; j<N; j++){
            int element;
            cin >> element;
            q.push(make_pair(j, element));
            pq.push(element);
        }

        int cnt = 0;
        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){
                pq.pop();
                cnt++;
                if(index == M){
                    cout << cnt << "\n";
                    break;
                }
            }else q.push(make_pair(index, value));
        }
    }

    return 0;
}