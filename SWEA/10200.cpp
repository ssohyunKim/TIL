//10200. 구독자 전쟁

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, A, B;
        int MAX, MIN;
		cin >> N >> A >> B;

        if(A>B) MAX = B;
        else MAX = A;

        MIN = (A+B)-N;
        if(MIN<0) MIN = 0;

        cout << "#" << test_case << " " << MAX << " " << MIN << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}