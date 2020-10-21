//쿼드 압축 후 개수 세기
#include <string>
#include <vector>

using namespace std;

int one = 0, zero = 0;
int map[1025][1025];
void compress(int x1, int x2, int y1, int y2){
    int count = 0;
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            if(map[i][j] == 1){
                count ++;
            }
        }
    }
    
    if((x2-x1)*(y2-y1) == count) one++;
    else if(count == 0) zero ++;
    else{
        int a = (x1 + x2)/2;
        int b = (y1 + y2)/2;
        compress(x1, a, y1, b);
        compress(x1, a, b, y2);
        compress(a, x2, y1, b);
        compress(a, x2, b, y2);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = arr[i][j];
        }
    }
    
    compress(0, n, 0, n);
    
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}