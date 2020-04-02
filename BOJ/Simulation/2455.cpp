#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = 0;
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        int in, out;
        cin >> out >> in;
        
        sum += in;
        sum -= out;  
        
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max << "\n";

    return 0;
}