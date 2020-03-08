#include <iostream>
#include <set>
using namespace std;
int digit[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int num;
set<int> s;
void DFS(int x, int y, int n){
    int temp = 0;
    if(n == 6){
        s.insert(num);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;
        temp = num;
        num = (num * 10) + digit[nx][ny];
        DFS(nx, ny, n+1);
        num = temp;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> diigt[i][j];
        }
    }
    
    for(int i=0; i<5; i++){
       for(int j=0; j<5; j++){
           DFS(i, j, 0);
       }
    }
    
    cout << s.size();
    
    return 0;
}
