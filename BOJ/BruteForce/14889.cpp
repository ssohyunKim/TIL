#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1. 두 팀을 나눈다.
// 2. 팀의 능력치의 합을 구한다. 
// 3. 두 팀의 능력치의 최솟값을 구한다.

int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    int s[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }

    vector<int> b(n); // 팀을 나눌 때 순열을 구하기 위한 배열
    for(int i=0; i<n/2; i++){
        b[i] = 1;
    }

    sort(b.begin(), b.end());
    int ans = 1000000000;
    do{
        // 1.
        vector<int> start, link;
        for(int i=0; i<n; i++){
            if(b[i] == 0){
                start.push_back(i); // 스타트팀 번호
            }else{
                link.push_back(i); // 링크팀 번호
            }
        }

        // 2.
        int one = 0;
        int two = 0;
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if(i == j) continue;
                one += s[start[i]][start[j]];
                two += s[link[i]][link[j]];
            }
        }
        
        // 3.
        int cha = one - two;
        if(cha < 0){
            cha = -cha;
        }
        if(ans > cha){
            ans = cha;
        }
    }while(next_permutation(b.begin(), b.end()));

    cout << ans << '\n';
    return 0;
}