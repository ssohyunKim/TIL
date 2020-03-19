#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

char star[5][9];
bool visited[13];
int cnt = 0;

vector< pair<int, int> > v;

bool check(){
    if ((star[0][4] - 'A' + 1) + (star[1][3] - 'A' + 1) + (star[2][2] - 'A' + 1) + (star[3][1] - 'A' + 1) != 26) return false;
    if ((star[0][4] - 'A' + 1) + (star[1][5] - 'A' + 1) + (star[2][6] - 'A' + 1) + (star[3][7] - 'A' + 1) != 26) return false;
    if ((star[1][1] - 'A' + 1) + (star[1][3] - 'A' + 1) + (star[1][5] - 'A' + 1) + (star[1][7] - 'A' + 1) != 26) return false;
    if ((star[3][1] - 'A' + 1) + (star[3][3] - 'A' + 1) + (star[3][5] - 'A' + 1) + (star[3][7] - 'A' + 1) != 26) return false;
    if ((star[4][4] - 'A' + 1) + (star[3][3] - 'A' + 1) + (star[2][2] - 'A' + 1) + (star[1][1] - 'A' + 1) != 26) return false;
    if ((star[4][4] - 'A' + 1) + (star[3][5] - 'A' + 1) + (star[2][6] - 'A' + 1) + (star[1][7] - 'A' + 1) != 26) return false;
 
    return true;
}
void DFS(int idx, int n){
    if(n == cnt){
        if(check() == true){ // x의 개수와 방문한 수가 같으면 종료
            for(int i=0; i<5; i++){
                for(int j=0; j<9; j++){
                    cout << star[i][j];
                }
                cout << "\n";
            }
            exit(0);
        }
    }
    for(int i=0; i<12; i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        star[v[idx].first][v[idx].second] = i + 'A';
        DFS(idx+1, n+1);
        star[v[idx].first][v[idx].second] = 'x';
        visited[i] = false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            cin >> star[i][j];
            
            if('A' <= star[i][j] && star[i][j] <= 'L'){ // 알파벳이면 true
                visited[star[i][j] - 'A'] = true;
            }else if(star[i][j] == 'x'){
                v.push_back(make_pair(i, j));
                cnt ++; // x의 개수를 세서 알파벳 채울 갯수 체크
            }
        }
    }
    
    DFS(0,0);
    
    return 0;
}

