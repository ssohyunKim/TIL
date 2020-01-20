#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int n;
int compare(vector <pair<int,int> > v, int k);
int main(void){
    cin >> n;
    
    vector< pair<int, int> > v;
    pair<int, int> p;
    
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    for(int k=0; k<n; k++){
        cout << compare(v, k) << " ";
    }
    
    return 0;
}
int compare(vector <pair<int,int> > v, int k){
    int rank = 1;
    
    for(int i=0; i<n; i++){

       if(i==k)
            continue;
       if(v[i].first > v[k].first && v[i].second > v[k].second){
            rank++;
       }
    }
    return rank;
}
