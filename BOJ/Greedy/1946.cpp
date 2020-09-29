//1946. 신입사원
#include <iostream>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        for(int i=0; i<N; i++){
            map<int, int> m;
            int answer = 0;
            int a, b;
            cin >> a >> b;
            m.insert(make_pair(a, b));

            int comp = m.at(1);
            int val = 0;
            
            for(auto iter=m.begin(); iter!=m.end(); iter++){
                val = iter->second;
                if(val <= comp) {
                    answer ++;
                }
                comp = val;
            }

            cout << answer << "\n";
        }
    }


    return 0;
}