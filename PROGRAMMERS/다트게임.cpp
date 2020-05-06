#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3] = {0, };   //점수배열
    int idx = 0;
    int cnt = 1;

    for(int i=0; i<dartResult.length(); i++){
        char c = dartResult[i];
        if(cnt == 1){
            score[idx] += c - '0';
            cnt ++;
        }else if(cnt == 2){
            if(c == 'S'){
                score[idx] = pow(score[idx], 1);
            }else if(c == 'D'){
                score[idx] = pow(score[idx], 2);
            }else if(c == 'T'){
                score[idx] = pow(score[idx], 3);
            }else if(c == '0'){ //10인 경우
                score[idx] = 10;
                cnt--;
            }
            cnt ++;
        }
        else if(cnt == 3){
            if (c == '*'){
                score[idx] *= 2;
                if(idx -1 >= 0){
                    score[idx-1] *= 2;
                }
            }else if(c == '#'){
                score[idx] *= (-1);
            }else { //없는 경우
                i--;
            }
            
            cnt = 1;
            idx++;
        }
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string array[7] = {"1S2D*3T", "1D2S#10S", "1D2S0T", "1S*2T*3S"
    , "1D#2S*3S", "1T2D3D#", "1D2S3T*"};

    for(int i=0; i<7; i++){
        cout << solution(array[i]) << "\n";
    }
    
    return 0;
}
