import java.util.ArrayList;

class Solution {
    public int solution(int[] nums) {
        ArrayList<Integer> num = new ArrayList<>();
        for (int n : nums) if (!num.contains(n)) num.add(n);
        int answer = nums.length / 2 > num.size() ? num.size() : nums.length / 2;
        
        return answer;
    }
}