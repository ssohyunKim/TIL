#include <iostream>
#include <deque>

using namespace std;

int main(int argc, const char *argv[])
{
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt = 0;

    cin >> n >> m;

    deque<int> dq;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    for (int i = 0, pick = 0; i < m; i++)
    {
        int pivot = 0;
        cin >> pick;
        if (dq.at(pivot) != pick)
        {
            //위치를 찾는다
            while (dq.at(pivot++) != pick);

            //left, right 중에 작은값 찾음
            int left = pivot - 1;
            int right = dq.size() - pivot + 1;

            if (left < right)
            {
                for (int i = 0; i < left; i++)
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
                cnt += left;
            }
            else
            {
                for (int i = 0; i < right; i++)
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
                cnt += right;
            }
        }
        dq.pop_front();
    }
    cout << cnt << "\n";
    return 0;
}