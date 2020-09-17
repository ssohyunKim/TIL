class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        
        int su = 0;
        int value = x;
        while(value!=0){
            su += value % 10;
            value = value / 10;
        }
        
        if(x % su==0) {
            answer = true;
        } else{
            answer = false;
        }
        
        return answer;
    }
}