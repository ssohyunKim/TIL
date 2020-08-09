// 2001. 파리 퇴치
#include<iostream>
#include<vector>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int map[15][15];
    int N, M;
    int answer = 0;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;

        memset(map, 0, sizeof(map));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }

        answer = 0;
        int select[M][M];
        
        for(int i=0; i<N-M+1; i++){
            for(int j=0; j<N-M+1; j++){
                int value = 0;
                for(int k=0; k<M; k++){
                    for(int p=0; p<M; p++){
                        value += map[k+i][p+j];
                    }
                }
                answer = max(answer, value);
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}