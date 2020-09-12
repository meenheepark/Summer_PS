import java.util.*;
import java.lang.Math;
import java.util.Arrays;

class Solution
{
    public int solution(int [][]board)
    {
        int answer = 0;
        int [][]ans = new int[board.length +1][board[0].length+1]; // 크기주의
        //Arrays.fill(ans, 10);
        for(int i = 0 ; i < board.length ; i++){
            for(int j = 0 ; j < board[0].length; j++){
                if(board[i][j] == 1) ans[i][j] = 1;
            }
        }

        for(int i = 1 ; i < board.length ; i++){
            for(int j = 1 ; j < board[0].length; j++){
                if(ans[i][j] == 1){
                    int r = Math.min(ans[i][j-1], ans[i-1][j]);
                    r = Math.min(r, ans[i-1][j-1]);
                    
                    ans[i][j] = r + 1;
                    answer = Math.max(answer, ans[i][j]);
                }
            }
        }
        
        return answer*answer;
    }
}
