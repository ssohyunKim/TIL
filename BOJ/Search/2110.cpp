//2110. 공유기 설치
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
int func(vector<int> v){
    int answer;
    int left = 1; //v.front()(X):최대간격이 v[0]값보다 작을 수 있기 때문
    int right = v.back();

    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 1;

        int x = v.front();
        for(int i = 1; i < v.size(); i++){
            int y = v.at(i);
            int d = y - x;
            if(d >= mid){ //현재 위치 공유기와 이전 설치한 공유기의 간격이 mid보다 크면 증가
                x = y;
                cnt ++;
            }
        }

        if(cnt < C) right = mid - 1;
        else{
            answer = mid;
            left = mid +1;
        }
    }

    return answer;
}
int main(){
    vector<int> v;

    cin >> N >> C;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    //탐색을 위한 정렬
    sort(v.begin(), v.end());

    cout << func(v);

    return 0;
}