#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string p){
    stack<char> s;
    
    for(int i=0; i<p.size(); i++){
        if(p[i] == '('){
            s.push(p[i]);
        }else{
            if(!s.empty()){
                s.pop();
            }else{
                return false;
            }
        }
    }
    
    if(!s.empty()){
        return false;
    }else{
        return true;
    }
}


string solution(string p) {
    string answer = "";
    string u,v;
    int left = 0, right = 0;
    // 1.
    if(p == ""){
        return "";
    }
    
    // 2.
    for(int i=0; i<p.size(); i++){
        if(p[i] == '('){
            left++; 
        }else{
            right++;
        }
        if(left == right){ // 짝이 맞으면
            u = p.substr(0, left+right);
            v = p.substr(left+right, p.size()-(left+right));
            break;
        }
    }
    
    //3.
    if(check(u)){
        u+=solution(v);
        answer+=u;
    }
    //4.
    else{
        string s = "";
        s.append("(");
        s+=solution(v);
        s.append(")");
        
        u = u.substr(1, u.size()-2);
        for(int i=0; i<u.size(); i++){
            if(u[i] == '('){
                s+=')';
            }else{
                s+='(';
            }
        }
        answer = s;
    }
    return answer;
}