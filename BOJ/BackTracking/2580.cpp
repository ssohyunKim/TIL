//2580. 스도쿠
#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int> > v;

void dfs(int index);
bool squareCheck(int x, int y, int n);
bool rowCheck(int x, int n);
bool colCheck(int y, int n);
int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
            //빈 칸의 좌표를 벡터에 넣어준다.
            if(sudoku[i][j]==0){
                v.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0);
    return 0;
}
void dfs(int index){
    if(index == v.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0); //출력 후에 exit()을 이용해 종료시키지 않으면 남아있는 재귀 호출을 전부 다 실행하서 시간초과가 발생
    }
    for(int i=1; i <=9; i++){
        int x = v[index].first;
        int y = v[index].second;
        if(squareCheck(x, y, i) && rowCheck(x, i) && colCheck(y, i)){
            sudoku[x][y] = i;
            dfs(index + 1);
            sudoku[x][y] = 0; //백트래킹
        }
    }
}
//3X3칸 고려
bool squareCheck(int x, int y, int n){
    x = x/3;
    y = y/3;
    for(int row = x * 3; row < (x * 3) + 3; row++){
        for(int col = y * 3; col < (y * 3) + 3; col++){
            if(sudoku[row][col] == n) 
                return false;
        }
    }
    return true;
}
//가로줄 고려
bool rowCheck(int x, int n){
    for(int i=0; i<9; i++){
        if(sudoku[x][i] == n)
            return false;
    }
    return true;
}
//세로줄 고려
bool colCheck(int y, int n){
    for(int i=0; i<9; i++){
        if(sudoku[i][y] == n)
            return false;
    }
    return true;
}
