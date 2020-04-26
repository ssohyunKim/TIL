#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int k;
char op[10];
bool selected[10];
int num[10];

vector<string> answer;
vector<char> v;

bool check(int idx, char c){
    if(c=='<'){
        if(v[idx]-'0' < v[idx+1]-'0'){
            return true;
        }else{
            return false;
        }
    }else if(c=='>'){
        if(v[idx]-'0' > v[idx+1]-'0'){
            return true;
        }else{
            return false;
        }
    }
}
void dfs(int cnt){
    if(cnt == k+1){
        // 부등호 관계를 만족시키는 지 확인
        bool flag = true;
        for(int i=0; i<k; i++){
            if(!check(i, op[i])){
                flag = false;
            }
        }
        // 계산해서 더하기
        if(flag){
            string s = "";
            for(int i=0; i<v.size(); i++){
                s += v[i];
            }
            answer.push_back(s);
        }
        return;
    }
    for(int i=0; i<10; i++){
        if(!selected[i]){
            selected[i] = true;
            v.push_back(num[i]+'0');
            dfs(cnt+1);
            v.pop_back();
            selected[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    // 부등호 입력받아서 배열에 넣기
    for(int i=0; i<k; i++){
        cin >> op[i];
    }
    // 0~9 까지의 숫자 배열에 넣기
    for(int i=0; i<10; i++){
        num[i] = i;
    }

    dfs(0);

    cout << answer.at(answer.size()-1) << "\n";
    cout << answer.at(0) << "\n";

    return 0;
}