import java.util.Arrays;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        Arrays.sort(routes, (o1, o2) -> {
            return o1[0] - o2[0];
        });
        int c = -30001;
        for (int[] r : routes) {
            if (r[0] > c) {
                answer++;
                c = r[1];
            }
            if (r[1] < c) c = r[1];
        }
        
        return answer;
    }
}