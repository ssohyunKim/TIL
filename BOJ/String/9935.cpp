#include <iostream>
#include <string>

using namespace std;

string s1,s2;
char c[1000001];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s1 >> s2;
    
    int k = 0; // 인덱스
    for(int i=0; i<s1.size(); i++){
        c[k++] = s1[i];
        
        int j = (int)s2.size();
        if(s1[i] == s2[--j]) //c4중 4부터 비교를 시작한다.
        {
            bool check = false;
            int size = k-(int)s2.length();
            for(int m=k-1; m>=size; m--){
                if(c[m] == s2[j--]){
                    check = true;
                }
                else{
                    check = false;
                    break;
                }
            }
            if(check){
                k -= s2.size();
            }
        }
    }
    if(k==0)
        cout<<"FRULA"<<endl;
    else{
        for(int i=0; i<k; i++){
            cout << c[i];
        }
        cout << "\n";
    }
    return 0;
}
