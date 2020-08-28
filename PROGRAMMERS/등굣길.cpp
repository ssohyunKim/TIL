//등굣길
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int route[101][101];
int solution(int m, int n, vector<vector<int> > puddles) {
    int answer = 0;

    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];

        route[y][x] = -1;
    }
    //route[i][j] : (i,j)에 도달하는 방법의 수
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
             if (i == 1 && j == 1) {
                route[i][j] = 1;
                continue;
            }
            if (route[i][j]==-1) route[i][j] = 0;
            else {
                route[i][j] = (route[i][j - 1] + route[i - 1][j]) % 1000000007;
            }
        }
    }
    
    answer = route[n][m];
    return answer;
}