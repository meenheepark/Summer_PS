import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = ""; // 10만명이라서 포문 대 포문이면 시간초과난다 맵써야함
        Map <String, Integer> map = new HashMap<String, Integer>();
        
        for(int i = 0 ; i < participant.length ; i++){
            if(map.get(participant[i]) == null){ // 아직안들어갔다
                map.put(participant[i], 1);
            }
            else{ // 동명이인
                int k = map.get(participant[i]) + 1;
                map.put(participant[i], k); // 키는 중복 허용 안됨
            }
        }
        
        for(int i = 0 ; i < completion.length ; i++){
            int k = map.get(completion[i]) - 1;
            map.put(completion[i], k); // 0이되어야 완주임.
        }
        
        for(String key : map.keySet()){
            if(map.get(key) == 1){
                answer = key;
                
            }
        }
        return answer;
    }
}
