#include <iostream>

using namespace std;

string s, p;
char c[1000000];
int result;

void check(string s, string p){
    bool flag = true;
    
    int n = (int)s.length();
    int m = (int)p.length();
    
    if(n>=m){
        for(int i=0; i<n-m ; i++){
             for(int j=0; j<m; j++){
                 if(s[i+j] == p[j]){
                     c[j] = p[j];
                 }else {
                     break;
                 }
             }
             // 넣은 문자 비교해서 같은 값인지 체크
             for(int j=0; j<m; j++){
                if(c[j] != p[j]){
                    flag = false;
                }else{
                    continue;
                }
            }
            
            // c배열 초기화
            memset(c,0,sizeof(c));
            
            // flag값이 true이면 빠져나오고 result 출력
            if(flag){
                result = 1;
                return;
            }
        }
    }else{
        cout << 0 << "\n";
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    cin >> p;

    check(s, p);
    
    cout << result << "\n";
    
    return 0;
}

