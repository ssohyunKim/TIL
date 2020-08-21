#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    vector<int> q;
    for (int i = 0; i < operations.size(); i++) {
        string s = operations[i];
        int max, min;
        if (s[0] == 'I') {
            //숫자넣기
            string a = s.substr(2, s.length() - 1);
            q.push_back(stoi(a));
        }
        else if (s[0] == 'D') {
            if (s[2] == '1') {
                //최댓값 삭제
                max = *max_element(q.begin(), q.end());
                for (int j = 0; j < q.size(); j++) {
                    if (max == q[j]) {
                        q.erase(q.begin() + j);
                    }
                }
            }
            else if (s[2] == '-') {
                //최솟값 삭제
                min = *min_element(q.begin(), q.end());
                for (int j = 0; j < q.size(); j++) {
                    if (min == q[j]) {
                        q.erase(q.begin() + j);
                    }
                }
            }
        }
    }

    if (q.size() != 0) {
        int max = 0, min = 0;
        for (int i = 0; i < q.size(); i++) {
            max = *max_element(q.begin(), q.end());
            min = *min_element(q.begin(), q.end());
        }
        answer.push_back(max);
        answer.push_back(min);
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}