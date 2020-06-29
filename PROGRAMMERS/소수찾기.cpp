#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool primeNumber(int k){
    if(k<2) return false;
    for(int i=2; i < k; i++){
        if(k % i ==0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    for(int i=0; i<numbers.size(); i++){
        v.push_back(numbers[i]-'0');
    }
    sort(v.begin(), v.end());
    vector<int> a;
    
    //모든 경우의 수
    do{
        for(int i=0; i<=v.size(); i++){
            int val = 0;
            for(int j=0; j<i; j++){
                val = (val*10) + v[j];
                a.push_back(val);
            }
        }    
    }while(next_permutation(v.begin(), v.end()));

    //중복제거
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
       
    for(int i=0; i<a.size();i++){
        if(primeNumber(a[i]))
            answer ++;
    }

    return answer;
}