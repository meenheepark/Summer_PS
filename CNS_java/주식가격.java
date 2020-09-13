class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        int cnt = 0;
        for(int i = 0 ; i < prices.length ; i++){
            for(int j = i+1 ; j < prices.length ; j++){
                cnt++;
                if(prices[i] > prices[j]) break;
            }
            answer[i] = cnt;
            cnt = 0;
        }
        return answer;
    }
}
