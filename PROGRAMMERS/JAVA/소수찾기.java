import java.util.*;

class Solution {
    public int solution(int n) {
        ArrayList<Integer> list = new ArrayList<Integer>();
		
		int answer = 1;
		if(n >= 7) answer += 3;
		else if(n >= 5) answer += 2;
		else if(n >= 3) answer++;	
		
		for(int i=2; i<=n; i++) {
			
			if(i % 2 == 0) continue;
			else if(i % 3 == 0) continue;
			else if(i % 5 == 0) continue;
			else if(i % 7 == 0) continue;
			
			boolean q = false;
			if(i >= 121) {
				for(int p=0; p<list.size(); p++) {
					if(i < list.get(p)*list.get(p)) break;
					if(i % list.get(p) == 0) {
						q = true;
						break;
					}
				}
			}
			if(q) continue;
			answer++;
			list.add(i);

		}
		return answer;
    }
}