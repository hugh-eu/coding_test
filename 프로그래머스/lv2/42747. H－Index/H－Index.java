import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Integer[] citationsInteger = Arrays.stream(citations).boxed().toArray(Integer[]::new);
        Arrays.sort(citationsInteger, Comparator.reverseOrder());
        boolean flag = false;
        for (int i = citationsInteger.length; i >= 0; i--) {
            for (int j = 0; j < citationsInteger.length; j++) {
                if (j == 0 && citationsInteger[j] < i) break;
                else if ((citationsInteger[j] < i && j >= i) || (citationsInteger[j] >= i && j == citationsInteger.length - 1)) {
                    answer = i;
                    flag = true;
                    break;
                } else if (citationsInteger[j] < i && j < i) {
                    break;
                }
            }
            if (flag) break;
        }
        
        return answer;
    }
}