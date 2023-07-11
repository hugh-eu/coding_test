import java.util.*;

class Solution {
    public ArrayList<Integer> solution(String[] name, int[] yearning, String[][] photo) {
        ArrayList<Integer> answer = new ArrayList<>();
        HashMap<String, Integer> point = new HashMap<>();
        for (int i = 0; i < name.length; i++) point.put(name[i], yearning[i]);

        for (String[] p : photo) {
            int sum = 0;
            for (String n : p) {
                if (point.containsKey(n)) sum += point.get(n);
            }
            answer.add(sum);
        }

        return answer;
    }
}