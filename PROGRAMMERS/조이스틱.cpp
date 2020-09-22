//조이스틱
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};

int solution(string name) {
    int answer = 0;
    int n = name.length();
    
    int num = 0;
    int turn = n-1;
    for(int i=0; i<name.length(); i++){
        num += array[name[i] - 'A'];
        
        int next = i+1;//다음문자
        while(next<n && name[next]=='A') next++; //오른쪽으로 이동
    
        turn = min(turn, i+n-next + min(i, n-next));
        //turn : 전부 오른쪽으로 이동하면서 바꿔나갔을 때의 최대 이동횟수
    } 
    answer = num + turn;
  
    return answer;
}