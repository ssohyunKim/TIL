import java.util.*;

class Solution {
    public int[] solution(long n) { 
        String str = Long.toString(n);
        int size = str.length();
        int[] answer = new int[size];
        int j = 0;
        for (int i = str.length() -1; i>=0; i--) {
            answer[j] = Integer.parseInt(String.valueOf(str.charAt(i)));
            j++;
        }
        return answer;
    }
}
