#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>

#define inf 987654321

using namespace std;

string s;
vector<string> res;
vector<pair<int, int>> pos;
void func(int cur, int state)
{
    if (cur == pos.size())
    {
        if (pos.size() != 0 && state == 0)
            return;
        priority_queue<int> pq;

        for (int i = 0; i < pos.size(); i++)
        {
            if (state & (1 << i))
            {
                pq.push(-pos[i].first);
                pq.push(-pos[i].second);
            }
        }
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (!pq.empty() && -pq.top() == i)
                pq.pop();
            else
                t += s[i];
        }
        res.push_back(t);
        return;
    }
    func(cur + 1, state);
    func(cur + 1, state | (1 << cur));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    stack<int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            pos.push_back({st.top(), i});
            st.pop();
        }
    }

    func(0, 0);

    sort(res.begin(), res.end());

    cout << res[0] << '\n';

    for (int i = 1; i < res.size(); i++)
    {
        if (res[i] == res[i - 1])
            continue;

        cout << res[i] << '\n';
    }
    return 0;
}