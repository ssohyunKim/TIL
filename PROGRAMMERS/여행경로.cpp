#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//주어진 경로를 전부 다 이용해야한다!!
//  티켓 : [["ICN", "COO"], ["ICN", "BOO"], ["COO", "ICN"], ["BOO", "DOO"]]
// 결과값 : ["ICN", "COO", "ICN", "BOO", "DOO"]
//만약에 그냥 알파벳 순으로 움직인다면 "ICN"-> "BOO" -> "DOO"에서 멈추게된다.
//따라서 현재 이동 횟수 == 티켓의 수를 만족했을 때, 해당 경로를 반환해야한다. 

bool dfs(string departure, vector<vector<string>> &tickets, vector<string> &answer, vector<bool> &visited, vector<string> &temp, int cnt) {
    temp.push_back(departure);

    if(cnt == tickets.size()) {
        answer = temp;
        return true;
    }

    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == departure && !visited[i]) {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, answer, visited, temp, cnt+1);
            if(success){
                return true;
            }
            visited[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    vector<bool> visited(tickets.size(), false);
    vector<string> temp;

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, visited, temp, 0);

    return answer;
}