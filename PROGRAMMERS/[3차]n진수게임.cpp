#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solve(int &n, int k){ //n:n진법, k:바꿀수
    string result="";
    char ch[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    while(k/n!=0){
        result+=ch[k%n];
        k/=n;
    }
    result+=ch[k%n];    
    reverse(result.begin(), result.end()); //뒤집기

    return result; 
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string s = "";
    for(int i=0; i<t*m; i++){
        s += solve(n, i);
    }
    
    //튜브의 순서만큼 필요한 문자열 구하기
    //m명의 사람 만큼, m씩 더하기
    int j=0;
    for(int i=p-1; i<s.size(); i+=m){
        answer += s[i];
        if(j+1==t){
            break;
        }
        j++;
    }
    
    return answer;
}