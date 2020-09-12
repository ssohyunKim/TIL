import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> num = new ArrayList<Integer>();
        
        int current = 10;
        for(int i=0; i<arr.length; i++){
            if(arr[i] != current){
                num.add(arr[i]);
                current = arr[i];
            } 
        }
        int[] answer = new int[num.size()];
        for(int i=0; i<num.size(); i++){
            answer[i] = num.get(i);
        }
        return answer;
    }
}