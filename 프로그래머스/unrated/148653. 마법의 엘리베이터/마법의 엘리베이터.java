class Solution {
    public int solution(int storey) {
        int answer = 0;
        
        int n = Integer.toString(storey).length();
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                if (storey % Math.pow(10, i) > 0) {
                    if (storey % Math.pow(10, i) >= 6 * Math.pow(10, i - 1)) {
                        answer += ((Math.pow(10, i) - (storey % Math.pow(10, i))) / Math.pow(10, i - 1)) + 1;
                    } else {
                        answer += (storey % Math.pow(10, i)) / Math.pow(10, i - 1);
                    }
                } else {
                    answer++;
                }
                break;
            }
            if (storey % Math.pow(10, i) >= 6 * Math.pow(10, i - 1)) {
                answer += (Math.pow(10, i) - (storey % Math.pow(10, i))) / Math.pow(10, i - 1);
                storey += Math.pow(10, i) - (storey % Math.pow(10, i));
            } else if (storey % Math.pow(10, i) == 5 && storey % Math.pow(10, i + 1) >= 5) {
                answer += (Math.pow(10, i) - (storey % Math.pow(10, i))) / Math.pow(10, i - 1);
                storey += Math.pow(10, i) - (storey % Math.pow(10, i));
            } else {
                answer += (storey % Math.pow(10, i)) / Math.pow(10, i - 1);
                storey -= storey % Math.pow(10, i);
            }
        }
        
        return answer;
    }
}