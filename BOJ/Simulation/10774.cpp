#include <iostream>

using namespace std;

// 1. 저지의 사이즈는 S, M, L 중 하나이다
// 2. 요구하는 번호가 맞고 사이즈는 같거나 그 이상이어야 한다
// 3. 두 명의 학생들이 같은 저지를 받을 수은 없다
// 4. 최대 학생 수 구하기
char jersey[1000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int J, A, ans = 0;

    cin >> J;
    cin >> A;

    for(int i=1; i<=J; i++){
        cin >> jersey[i];
    }

    char num;
    int size;
    for(int i=1; i<=A; i++){
        cin >> num >> size;
        if(jersey[size] == 'X') continue;
        switch (num)
        {
        case  'S':
            if(jersey[size] != 'X'){
                ans ++;
                jersey[size] = 'X';
                break;
            }
        case  'M':
            if(jersey[size] == 'M' || jersey[size] == 'L'){
                ans ++;
                jersey[size] = 'X';
                break;
            }

        case  'L':
            if(jersey[size] == 'L'){
                ans ++;
                jersey[size] = 'X';
                break;
            }
        default:
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}