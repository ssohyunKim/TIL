import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        int min = 100000;
        
        for(int i=0; i<arr.length; i++){
            if(arr[i] < min) min = arr[i];
        }
        int cnt = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] == min) cnt ++;
        }
        
        if(cnt == arr.length){
            answer = new int[1];
            answer[0] = -1;
        }else{
            answer = new int[arr.length - cnt];
        
            int j = 0;
            for(int i=0; i<arr.length; i++){
                if(arr[i] == min) continue;
                else{
                    answer[j] = arr[i];
                    j++;
                }
            }
        }
        
        return answer;
    }
}