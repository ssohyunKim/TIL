//모의고사
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int first_count = 0, second_count = 0, third_count = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        int first_index = i % (first.size());
        int second_index = i % (second.size());
        int third_index = i % (third.size());

        if (answers[i] == first[first_index])
        {
            first_count++;
        }
        if (answers[i] == second[second_index])
        {
            second_count++;
        }
        if (answers[i] == third[third_index])
        {
            third_count++;
        }
    }
    vector<pair<int, int>> v;
    v.push_back({first_count, 1});
    v.push_back({second_count, 2});
    v.push_back({third_count, 3});

    sort(v.begin(), v.end());

    int MAX = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first > MAX)
            MAX = v[i].first;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == MAX)
            answer.push_back(v[i].second);
    }

    return answer;
}