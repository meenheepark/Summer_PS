import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder()); // priorities 값
        for (int i : priorities) {
            queue.offer(i);
        }
        while (!queue.isEmpty()) { // 포문 다 돌고도 남을수도 있기때문에
            for (int i = 0; i < priorities.length; i++) {
                if (priorities[i] == queue.peek()) {
                    if (location == i) {
                        return answer;
                    }
                    answer++;
                    queue.poll();
                }
            }
        }
        return answer;
    }
}
