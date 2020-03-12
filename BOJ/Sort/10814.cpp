#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair <int, string> a, pair <int, string> b){
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    
    vector < pair <int, string> > v;
    pair <int, string> p;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}
