#include <iostream>

using namespace std;

int t, n;
string bk[11], pk[11];
string en[11], de[11];
int idx;

void decode(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pk[i] == bk[j]){
                de[j] = en[i];
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << de[i] << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
       
        for(int i=0; i<n; i++){
            cin >> bk[i];
        }
        for(int i=0; i<n; i++){
            cin >> pk[i];
        }
        for(int i=0; i<n; i++){
            cin >> en[i];
        }
        decode();
    }
    return 0;
}

