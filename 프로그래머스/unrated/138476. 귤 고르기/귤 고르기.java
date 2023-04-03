import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        Map<Integer, Integer> cnt = new HashMap<>();

        for (int i : tangerine) {
            if (cnt.containsKey(i)) cnt.put(i, cnt.get(i) + 1);
            else cnt.put(i, 1);
        }

        List<Map.Entry<Integer, Integer>> entryList = new LinkedList<>(cnt.entrySet());
        entryList.sort(new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        for(Map.Entry<Integer, Integer> entry : entryList){
            answer++;
            k -= entry.getValue();
            if (k <= 0) break;
        }
        
        
        
        return answer;
    }
}