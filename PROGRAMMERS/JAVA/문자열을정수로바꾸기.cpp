class Solution {
    public int solution(String s) {
        int answer = 0;
        
        String number = "";
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='-' || s.charAt(i)=='+') continue;
            else number+=s.charAt(i);
        }
        
        answer = Integer.parseInt(number);
        
        if(s.charAt(0)=='-') answer*=-1;
        
        return answer;
    }
}