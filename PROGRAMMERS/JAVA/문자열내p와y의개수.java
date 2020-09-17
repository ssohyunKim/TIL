class Solution {
    boolean solution(String s) {
        boolean answer = true;

        int count_p = 0;
        int count_y = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == 'p' || s.charAt(i) =='P') count_p++;
            if(s.charAt(i) == 'Y' || s.charAt(i) =='y') count_y++;
        }
        if(count_p == count_y) answer = true;
        else answer = false;

        return answer;
    }
}