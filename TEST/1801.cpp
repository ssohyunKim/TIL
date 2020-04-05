#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

/*
* Time complexity : TODO
* Space complexity : TODO
*/
int main(int argc, const char *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int cnt = 0;
        char buf[BUFSIZ];

        cin >> buf;

        int len = strlen(buf);
        for (int i = 0; i < len; i++)
        {
            cnt++;
            if (buf[i] != buf[i + 1])
            {
                cout << buf[i] << cnt;
                cnt = 0;
            }
        }
    }
    return 0;
}