//11656. 접미사 배열
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<string> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    
    for(int i=0; i<=s.length()-1; i++){
        string a="";
        for(int j=i; j<s.length(); j++){
            a+=s[j];
        }
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] <<"\n";
    }

    return 0;
}