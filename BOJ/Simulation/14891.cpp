#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int k;
int arr[4][8];

void rotate(int n, int dir){
    int temp[8];
    
    if(dir == 1){ //시계방향
        for(int i=0; i<8; i++){
            temp[(i+1)%8] = arr[n][i];
        }
    }else if(dir == -1){ //반시계방향
        for(int i=0; i<8; i++){
            temp[i] = arr[n][(i+1)%8];
        }
    }
    
    for(int i=0; i<8; i++){
        arr[n][i] = temp[i];
    }
}

void solve(int n, int dir){ // n:톱니번호, dir:회전방향
    // 초기화
    vector<int> d(4);
    
    d[n-1] = dir;
    if(n == 1){  // 0번째 톱니
        if(arr[0][2]^arr[1][6]){
            d[1] = d[0]*(-1);
        }
        if(arr[1][2]^arr[2][6]){
            d[2] = d[1]*(-1);
        }
        if(arr[2][2]^arr[3][6]){
            d[3] = d[2]*(-1);
        }
    }
    if(n == 2){ //1번째 톱니
        if(arr[1][2]^arr[2][6]){
            d[2] = d[1]*(-1);
        }
        if(arr[0][2]^arr[1][6]){
            d[0] = d[1]*(-1);
        }
        if(arr[2][2]^arr[3][6]){
            d[3] = d[2]*(-1);
        }
    }
    if(n == 3){ //2번재 톱니
        if(arr[2][2]^arr[3][6]){
            d[3] = d[2]*(-1);
        }
        if(arr[2][6]^arr[1][2]){
            d[1] = d[2]*(-1);
        }
        if(arr[1][6]^arr[0][2]){
            d[0] = d[1]*(-1);
        }
    }
    if(n == 4){ //3번째 톱니
        if(arr[3][6]^arr[2][2]){
            d[2] = d[3]*(-1);
        }
        if(arr[2][6]^arr[1][2]){
            d[1] = d[2]*(-1);
        }
        if(arr[1][6]^arr[0][2]){
            d[0] = d[1]*(-1);
        }
    }
    
    // 방향 체크
//    for(int i=0; i<4; i++){
//        printf("%d" , d[i]);
//    }
    
    for(int i=0; i<4; i++){
        if(d[i]!=0){
            rotate(i, d[i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    scanf("%d", &k);
    
    for(int i=k; i>0; i--){
        int n,m;
        scanf("%d %d", &n, &m);
        solve(n, m);
    }
    
    // 회전 후 톱니바퀴 출력
//    for(int i=0; i<4; i++){
//       for(int j=0; j<8; j++){
//           printf("%d", arr[i][j]);
//       }
//       printf("\n");
//    }
    
    for(int i=0; i<4; i++){
        if(arr[i][0] == 1){
            ans += arr[i][0] * pow(2,i);
        }
    }
    
    printf("%d" , ans);
    return 0;
}

