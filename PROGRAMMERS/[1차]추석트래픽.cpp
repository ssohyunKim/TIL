#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> Split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        internal.push_back(temp);
    }

    return internal;
}

int solution(vector<string> lines)
{

    vector<string> temp;     // 임시 저장소
    vector<int> start_point; // 완료 시간
    vector<int> end_point;   // 시작 시간

    int size = lines.size();
    int answer = 0;
    int check = 0;
    int end_time = 0;
    int process_time = 0;

    // 데이터 split 처리
    for (int i = 0; i < size; ++i)
    {
        // 날짜[0], 완료시간[1], 처리시간[2]으로 나눈다.
        temp = Split(lines[i], ' ');

        if (Split(Split(temp[1], ':')[2], '.')[1].length())

            // 완료시간
            end_time = stoi(Split(temp[1], ':')[0]) * 3600000 + stoi(Split(temp[1], ':')[1]) * 60000 + stof(Split(temp[1], ':')[2]) * 1000;

        // 처리시간
        process_time = stof(temp[2]) * 1000 - 1;

        // 완료시간 저장
        end_point.push_back(end_time);

        // 시작시간 저장
        start_point.push_back(end_time - process_time);
    }

    for (int i = 0; i < size; ++i)
    {
        // --------------------------------------------------------- 시작 시점 검사

        // 저장소 초기화 && 본인추가
        check = 0;

        // 범위는 시작시점의 1초 전이다.
        int range = start_point[i] - 999;

        for (int j = 0; j < size; ++j)
        {
            // 1. 시작포인트가 범위에 포함하는 경우 종료시점은 무관하다.) 시작지점이 범위보다 크거나 같고 현재 시작지점보다 작을 경우
            // 2. 시작포인트가 범위 이전에 있지만 종료시점이 범위 이상에 있는 경우 )
            if (range <= start_point[j] && start_point[j] <= start_point[i])
                check++;
            else if (range >= start_point[j] && end_point[j] >= range)
                check++;
        }

        // 최대 요청량 갱신
        if (answer < check)
            answer = check;
    }

    return answer;
}
