class Solution {
    public int solution(int n) {
        int answer = 0;
        String s = Integer.toBinaryString(n);
        int cnt =0;
        for(char c : s.toCharArray()){
            if(c == '1') cnt++;
        }
        for(int i = n+1 ; i <= 1000000 ; i++){
            String ans = Integer.toBinaryString(i);
            int cnt2 = 0;
            for(char c: ans.toCharArray()){
                if(c == '1') cnt2++;
            }
            if(cnt == cnt2){
                answer = i;
                break;
            }
        }
        return answer;
    }
}
