import java.util.Arrays;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, (o1, o2) -> {
            return o1[0] - o2[0];
        });
        int[] areaMissile = {-1, -1};
        for (int[] t : targets) {
            if ((areaMissile[0] > -1) && ((areaMissile[0] <= t[0] && t[0] < areaMissile[1]) || (areaMissile[0] < t[1] && t[1] <= areaMissile[1]))) {
                areaMissile[0] = Math.max(t[0], areaMissile[0]);
                areaMissile[1] = Math.min(t[1], areaMissile[1]);
            } else {
                areaMissile[0] = t[0];
                areaMissile[1] = t[1];
                answer++;
            }
        }
        
        return answer;
    }
}