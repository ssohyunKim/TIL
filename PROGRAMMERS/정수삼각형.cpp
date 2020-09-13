#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > triangle) {
    int answer = 0;
    
    int n = triangle.size();
    int array[501][501];
    
    array[0][0] = triangle[0][0];
    
    //가장자리 합 구하기
    for(int i=1; i<n; i++){
        array[i][0] = array[i-1][0] + triangle[i][0];
        array[i][i] = array[i-1][i-1] + triangle[i][i];
    
    }
    //삼각형 내부 구하기
    for(int i=2; i<n; i++){
        for(int j=1; j<i; j++){
            array[i][j] = max(array[i-1][j-1], array[i-1][j]) + triangle[i][j];
        }
    }

    for(int i=0; i<n; i++){
        answer = max(answer, array[n-1][i]);
    }
    return answer;
}