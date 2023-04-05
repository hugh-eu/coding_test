import java.util.Arrays;
import java.util.ArrayList;

class Solution {
    public int solution(int[][] scores) {
        int answer = 0;
        
        int[] wh = new int[]{scores[0][0], scores[0][1]};
        
        Arrays.sort(scores, (a, b) -> (b[0] + b[1]) - (a[0] + a[1]));
        
        ArrayList<int[]> tempScores = new ArrayList<>();
        for (int[] s : scores) {
            if (wh[0] < s[0] && wh[1] < s[1]) return -1;
            answer++;
            tempScores.add(new int[]{s[0], s[1]});
            if (s[0] + s[1] <= wh[0] + wh[1]) break;
        }

        for (int i = 0; i < tempScores.size(); i++) {
            for (int j = 0; j < tempScores.size(); j++) {
                if (i == j) continue;
                if (tempScores.get(i)[0] < tempScores.get(j)[0] && tempScores.get(i)[1] < tempScores.get(j)[1]) {
                    if (wh[0] + wh[1] < tempScores.get(i)[0] + tempScores.get(i)[1]) answer--;
                    break;
                }
            }
        }
        
        return answer;

    }
}