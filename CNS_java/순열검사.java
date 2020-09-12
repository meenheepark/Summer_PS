class Solution {
    public boolean solution(int[] arr) {
        boolean answer = true;

        int []a = new int[100001]; // 런타임에러 안나게할것
        //a = {0};
        int max = -1;
        for(int i = 0 ; i < arr.length ; i++){
            a[arr[i]]++;
            if(max < arr[i]) max = arr[i];
            if(a[arr[i]] > 1){
                answer = false;
                break;
            } 
        }
        
        for(int i = 1 ; i <= max ; i++){
            if(a[i] == 0){
                answer = false;
                break;
            } 
        }
        
        return answer;
    }
}
