import java.util.*;
import java.lang.Math;

class Solution
{
    public int solution(int [][]board)
    {
        int answer = 0;

        for(int i = 1 ; i < board.length ; i++){
            for(int j = 1 ; j < board[i].length; j++){ // 밑으로 내려가니까 덮어씌워줘도된다.
                if(board[i][j] == 1){
                    int r = Math.min(board[i][j-1], board[i-1][j]);
                    r = Math.min(r, board[i-1][j-1]);
                    
                    board[i][j] = r + 1;
                    //answer = Math.max(answer, board[i][j]);
                }
            }
        }
        
        for(int i = 0 ; i < board.length ; i++){
            for(int j = 0 ; j < board[i].length; j++){
                if(board[i][j] > 0){ // 1x1인경우가 있을수도 있어서 검사해야됨
                    answer = Math.max(answer, board[i][j]);
                }
            }
        }
        
        return answer*answer;
    }
}
