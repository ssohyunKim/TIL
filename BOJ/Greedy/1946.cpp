//1946. 신입사원
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
int T, N;
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        for(int i=0; i<N; i++){
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        sort(v.begin(), v.end());

        int answer = 1;
        int rank = v.front().second;
        for(int i=1; i<N; i++){
            if(v[i].second < rank) {
                answer ++;
                rank = v[i].second;
            }
        }
        cout << answer << "\n";
        v.clear();
    }
    return 0;
}
