class Solution {
    public int solution(int sticker[]) {
        int answer = -1;
        int size = sticker.length;
        if(size <= 3){ // 하나만 뗄 수 있다
            for(int i = 0 ; i < size ; i++){
                answer = Math.max(answer, sticker[i]);
            }
            return answer;
        }
        
        int []dp1 = new int[sticker.length]; // 첫번째거를 떼고 마지막걸 안뗌
        int []dp2 = new int[sticker.length]; // 두번째거 떼고 마지막거 뗌
        dp1[0] = sticker[0]; dp1[1] = sticker[0];
                dp2[0] = 0; dp2[1] = sticker[1];
        for(int i = 2 ; i < sticker.length ; i++){
            if(i == sticker.length - 1){ //끝
                dp1[i] = Math.max(dp1[i-2], dp1[i-1]); // 마지막거를 더할 수 없음
                dp2[i] = Math.max(dp2[i-2] + sticker[i], dp2[i-1]);
            }
            else{
                dp1[i] = Math.max(dp1[i-2] + sticker[i], dp1[i-1]);
                dp2[i] = Math.max(dp2[i-2] + sticker[i], dp2[i-1]);
            }
        }
        answer = Math.max(dp1[sticker.length -1], dp2[sticker.length -1]);
        return answer;
    }
}
