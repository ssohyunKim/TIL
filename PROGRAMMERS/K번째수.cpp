// k번째수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    int i, j, k;
    for(int x = 0; x < commands.size(); x++){
        i = commands[x][0];
        j = commands[x][1];
        k = commands[x][2];
        
        vector<int> v;
        for(int y = i-1; y < j; y++){
            v.push_back(array[y]);
        }
        
        sort(v.begin(), v.end());
        
        answer.push_back(v.at(k-1));
    }
    return answer;
}