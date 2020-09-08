//문자열압축
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length(); //압축되지 않는 문자열 일때 최댓값 
    
    for (int i = 1; i <= s.length() / 2; i++) { //1개부터 문자열 길이의 반까지 압축 가능
        int len = s.length();
        
        for (int j = 0; j < s.length(); j++) {
            for (int count = 0, z = i; j + z < s.length(); z += i){ //문자열의 현재 위치 + 압축 개수 와 다음 문자열을 비교 예) aabbc(2압축): aa 와 ab를 비교
                if (s.substr(j, i) == s.substr(j + z, i))   //문자열이 같으면 갯수 증가
                    count++;
                else { //뒤에부분이 일치하지않는다면 count확인후 중복되는 문자열만큼 길이줄인다.
                    len -= i * count; 
                    
                    if (count)
                        len += to_string(count + 1).length(); //숫자길이만큼 길이증가
                    
                    j += z - 1;
                    break;
                }
                if (j + z + i >= s.length()) { //압축이 된 상태에서 뒤에 계산이 안되면 압축 후 추가하고 나머지를 뒤에 추가한다.
                    len -= i * count;
                    len += to_string(count + 1).length();
                    j += z;
                }
            }
        }
        if (len < answer)    answer = len; //문자열 길이 비교해서 최솟값 선택
    }
    return answer;
}