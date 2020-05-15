#include <iostream>

using namespace std;
//규칙찾기!!
//인접한 번호끼리 게임. 이기면 다음 라운드에 진출하고, 지면 떨어짐
//만약 라운드의 참가자가 홀수명이라면, 마지막 번호를 가진 참가자는 다음 라운드로 자동 진출
//다음라운드 매기는 순서는 처음 번호의 순서를 유지하면서 1번부터 매김.
//번호를 다시 배정받은 후에 한 명만 남을 때까지 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);g

    int n, kim, lee;
    int round = 0;

    cin >> n >> kim >> lee;
    while(kim!=lee){
        kim = (kim+1)/2;
        lee = (lee+1)/2;
        round++;
    }

    cout << round <<"\n";

    return 0;
}