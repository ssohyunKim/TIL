#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, map<int, vector<string>>> m;
    int index = 0;
 
    for(int i = 0; i < files.size(); i++){
        string head = "";
        string number = "";
        int num = 0;
        bool flag = true;  //flag를 두어서 숫자일 때를 처리
 
        for(int j = 0; j < files[i].size(); j++){
            if(flag == true){   //head
                if(files[i][j] != ' ' || files[i][j] != '.' || files[i][j] != '-'){
                    if(files[i][j] >= '0' && files[i][j] <= '9'){
                        flag = false;
                        j--;
                    }else
                         //소문자 대문자 구분 없게 하기 위해 tolower함수 사용
                        head += tolower(files[i][j]);
                }
            }else if(files[i][j] >= '0' && files[i][j] <= '9'){  //number
                if(files[i][j] == '0') 
                    continue;
                else{
                    while(true){
                        if(files[i][j] >= '0' && files[i][j] <= '9')
                            number += files[i][j];
                        else{
                            num = atoi(number.c_str());
                            break;
                        }
                        j++;
                    }
                }          
            }else{
                num = atoi(number.c_str());
                break;
            }
        }
        m[head][num].push_back(files[i]);
    }
 
    for_each(m.begin(), m.end(), [&](pair<string, map<int, vector<string>>> itr){
            for_each(itr.second.begin(), itr.second.end(), [&](pair<int, vector<string>> itr2){
                for(int i = 0; i < itr2.second.size(); i++)
                    answer.push_back(itr2.second[i]);
            });
    });    
    return answer;
}