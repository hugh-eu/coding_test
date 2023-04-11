class Solution {
    public int[] solution(int[] sequence, int k) {
        
        int[] answer = {};
        int sum = sequence[0];
        int left = 0, right = 0;
        int range = 1000000;
        while (right < sequence.length) {
            if (sum == k) {
                if (right - left < range) {
                    answer = new int[]{left, right};
                    range = right - left;
                }
                sum -= sequence[left++];
            } else if (sum < k) {
                right++;
                if (right < sequence.length) sum += sequence[right];
            } else {
                sum -= sequence[left++];
            }
        }
        return answer;
    }
}