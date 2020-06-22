#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string token;
    int maxi = -2147000000;
    int mini = 2147000000;
    stringstream ss(s);

    while(ss >> token){
        int temp = stoi(token);
        if(maxi < temp){
            maxi = temp;
        }
        if(mini > temp){
            mini = temp;
        }
    }
    string result = to_string(mini) +" "+to_string(maxi);
    answer += result;
    return answer;
}
