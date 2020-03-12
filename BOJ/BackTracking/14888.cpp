#include <iostream>

using namespace std;

int n;
int MAX=-1000000000, MIN=1000000000;
int num[11]; // 수 배열
int o[4]; // 연산자 배열

void DFS(int cal, int cnt){ //cal:계산값, cnt:연산횟수
    
    //printf("%d: %d %d\n", cnt, MAX, MIN);
    if(cnt == n){
        if(cal > MAX){
            MAX = cal;
        }
        if(cal < MIN){
            MIN = cal;
        }
    }else{
        if(o[0]){ // +연산자가 있을때
            o[0]--;
            DFS(cal+num[cnt], cnt+1);
            o[0]++;
        }
        if(o[1]){ // -연산자가 있을때
            o[1]--;
            DFS(cal-num[cnt], cnt+1);
            o[1]++;
        }
        if(o[2]){ // *연산자가 있을때
            o[2]--;
            DFS(cal*num[cnt], cnt+1);
            o[2]++;
        }
        if(o[3]){ // /연산자가 있을떄
            o[3]--;
            DFS(cal/num[cnt], cnt+1);
            o[3]++;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    for(int i=0; i<4; i++){
        cin >> o[i];
    }
    
    DFS(num[0], 1);
    
    cout << MAX << "\n" << MIN << "\n";
    return 0;
}
