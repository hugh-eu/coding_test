class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            for (int s : section) {
                if (i == s) {
                    answer++;
                    i = s + m - 1;
                    break;
                }
            }
        }

        return answer;
    }
}