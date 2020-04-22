#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int LIMIT = 10;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<int> gen(int k){
    vector<int> a(LIMIT);
    for(int i=0; i<LIMIT; i++){
        a[i] = k%4; // a[i] = (k&3) 과 같다.
        k /=4; // k>> 2; 비트를 오른쪽으로 두번 이동
    }
    return a;
}
pair<bool, bool> simulate(vector<string> &a, int k, int &x, int &y){
    if(a[x][y] == '.') return make_pair(false, false);
    int n = a.size();
    int m = a[0].size();
    bool moved = false;
    while(true){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx <0 || ny < 0 || nx >= n || ny >=m){
             return make_pair(moved, false);
        }
        if(a[nx][ny == '#']){  // 다음 칸의 상태가 벽
            return make_pair(moved, false);
        }else if(a[nx][ny == 'R'] || a[nx][ny == 'B']){ // 다음 칸에 구슬이 있는 경우 이동안됨
            return make_pair(moved, false);
        }else if(a[nx][ny == '.']) { // 빈칸이 있으면 이동
            swap(a[nx][ny], a[x][y]); // R . => .R
            x = nx;
            y = ny;
            moved = true;
        } else if(a[nx][ny == '0']){ // 구멍에 빠졌으면 빈칸으로 만들어준다
            a[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
    return make_pair(false, false);  
}
int check(vector<string> a, vector<int> &dir){
    int n = a.size();
    int m = a[0].size();
    int hx, hy, rx, ry, bx, by;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            if(a[i][j] == 'O'){  // 구멍의 위치
                hx = i; hy = j;
            } else if(a[i][j] == 'R'){ // 빨간 구슬의 위치
                rx = i; ry = j;
            } else if(a[i][j] == 'B'){ // 파란 구슬의 위치
                bx = i; by = j;
            } 
        }
    }
    int cnt = 0;
    for(int k : dir){
        cnt += 1;  // 움직인 횟수 저장
        bool hole1 = false, hole2 = false;  // 빨간 구슬이 구멍에 빠졌는지 체크, 파란구슬이 구멍에 빠졌는지 체크
        while(true){
            auto p1 = simulate(a, k, rx, ry);  // 리턴 값 = (움직였는 지, 구멍에 빠졌는 지)
            auto p2 = simulate(a, k, bx, by);
            if(p1.first == false && p2.first == false){  // 빨간 구슬, 파란 구슬 안움직이면
                break;
            }
            if(p1.second) hole1 = true; //빨간 구슬이 구멍에 빠졌을 때 
            if(p2.second) hole2 = true; //파란 구슬이 구멍에 빠졌을 때 
        }
        if(hole2) return -1;
        if(hole1) return cnt;
    }
    return -1;
}
bool valid(vector<int> &dir){
    int l = dir.size();
    for(int i=0; i+1 <l; i++){
        // 반대 방향 체크
        if(dir[i] == 0 && dir[i+1] == 1) return false;
        if(dir[i] == 1 && dir[i+1] == 0) return false;
        if(dir[i] == 2 && dir[i+1] == 3) return false;
        if(dir[i] == 3 && dir[i+1] == 2) return false;
        // 같은 방향 체크
        if(dir[i] == dir[i+1]) return false;
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a(n);
    }
    int ans = -1;
    for (int k = 0; k < (1 << (LIMIT * 2)); k++)
    {
        vector<int> dir = gen(k);
        if (!valid(dir)) // 같은 방향으로 연속해서 두번 이동하거나, 한 방향으로 이동한 다음 반대 방향으로 이동하는 경우가 아닐 때
            continue;
        int cur = check(a, dir);
        if (cur == -1)
            continue;
        if (ans == -1 || ans > cur)
            ans = cur;
    }
    cout << ans << "\n";

    return 0;
}