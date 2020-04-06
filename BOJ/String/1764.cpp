#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    vector<string> a;      //듣도 못한 사람
    vector<string> result; //듣도 보도 못한 사람

    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 이진 탐색을 위한 정렬
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (binary_search(a.begin(), a.end(), s))
        {
            result.push_back(s);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() <<"\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}