import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        int k = n;
        while(k != 0){
            int r = k % 10;
            k /= 10;
            answer += r;
        }
        
        return answer;
    }
}
