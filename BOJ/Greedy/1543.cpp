#include <iostream>

using namespace std;
int cnt = 0;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string d, w;
    
    getline(cin, d); //공백이 들어갈 수 있으므로 getline으로 받아줘야한다.
    getline(cin, w);
    
    if(d.length() < w.length()){ // 단어가 문서보다 클 때는 0출력
        cout << 0 << "\n";
    }else{
        for(int i=0; i<=d.size()-w.size(); i++){
            bool check = true;
            
            for(int j=0; j<w.size(); j++){ //word가 있는지 체크
                //printf("%c %c : %d\n", d[i], w[j], cnt);
                if(d[i+j]!=w[j]){
                    check = false;
                    break;
                }
            }
            if(check){
                cnt ++;
                i += w.size()-1; // -1 해줘야한다!
            }
        }
        cout << cnt << "\n";
    }
}

