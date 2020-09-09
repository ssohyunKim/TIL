//1764. 듣보잡
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
int main(){
    cin >> N >> M;
    map<string, int> m;
    vector<string> answer;

    //듣도 못한 사람
    for(int i=0; i<N; i++){
        string s1;
        cin >> s1;
        m.insert(make_pair(s1, 1));
    }

    //보도 못한 사람
    for(int i=0; i<M; i++){
        string s2;
        cin >> s2;

        // for(auto iter=m.begin(); iter!=m.end(); iter++){
        //     string name = iter -> first;
        //     if(name == s2){
        //         m[name]++;
        //     }
        // }
        if(m.find(s2)!=m.end()){
            m[s2]++;
        }
    }

    for(auto iter=m.begin(); iter!=m.end(); iter++){
        int cnt = iter->second;
        
        if(cnt==2){
            answer.push_back(iter->first);
        }
    }

    //사전 순 출력
    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << "\n";
    }
    
    return 0;
}