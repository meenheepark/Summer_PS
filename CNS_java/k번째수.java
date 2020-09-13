import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i = 0 ; i < commands.length ; i++){
            int start = commands[i][0];
            int end = commands[i][1];
            int ans = commands[i][2];
            
            int[] k = new int[end-start+1];
            int idx = 0;
            for(int j = start - 1 ; j <= end - 1 ; j++){
                k[idx] = array[j];
                idx++;
            }
            Arrays.sort(k);
            
            answer[i] = k[ans-1];
        }
        
        return answer;
    }
}
