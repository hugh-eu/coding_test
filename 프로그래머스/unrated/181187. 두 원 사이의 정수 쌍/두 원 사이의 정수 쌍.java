class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        for (int i = 1; i < r2; i++) {
            if (i < r1) {
                answer += Math.floor(Math.sqrt(Math.pow(r2, 2) - Math.pow(i, 2))) -
                        Math.ceil(Math.sqrt(Math.pow(r1, 2) - Math.pow(i, 2))) + 1;
            } else if (i == r1) {
                answer += Math.floor(Math.sqrt(Math.pow(r2, 2) - Math.pow(i, 2))) -
                        Math.ceil(Math.sqrt(Math.pow(r1, 2) - Math.pow(i, 2)));
            } else {
                answer += Math.floor(Math.sqrt(Math.pow(r2, 2) - Math.pow(i, 2)));
            }
        }
        answer *= 4;
        answer += (r2 - r1 + 1) * 4;
        
        return answer;
    }
}