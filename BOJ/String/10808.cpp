#include <iostream>

using namespace std;

string s;
int alphabet[26]={0,};

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    for(int i=0; i<s.size(); i++){
        alphabet[s[i]-'a']++;
    }
    
    for(int i=0; i<26; i++){
        cout << alphabet[i] << " ";
    }
    return 0;
}
