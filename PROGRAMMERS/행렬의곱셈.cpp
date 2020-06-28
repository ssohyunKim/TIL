#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int val = 0;
    
    for(int i=0; i<arr1.size(); i++){
        vector<int> v;
        for(int j=0; j<arr2[0].size(); j++){
            for(int k=0; k<arr2.size(); k++){
                val += arr1[i][k] * arr2[k][j];   
            } 
            v.push_back(val);
            val = 0;
        }
        answer.push_back(v);
    }
    return answer;
}