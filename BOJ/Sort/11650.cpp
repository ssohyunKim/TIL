#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    vector < pair<int,int> > v;
    pair <int,int> p;

    cin >> n;
 
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}
