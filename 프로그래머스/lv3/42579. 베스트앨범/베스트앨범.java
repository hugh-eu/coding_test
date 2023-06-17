import java.util.*;

class Solution {
    public ArrayList<Integer> solution(String[] genres, int[] plays) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        HashMap<String, Integer> sortGenres = new HashMap<>();
        HashMap<String, HashMap<Integer, Integer>> sortPlays = new HashMap<>();
        for (int i = 0; i < plays.length; i++) {
            if (sortGenres.keySet().contains(genres[i])) {
                sortGenres.put(genres[i], sortGenres.get(genres[i]) + plays[i]);
            } else {
                sortGenres.put(genres[i], plays[i]);
                sortPlays.put(genres[i], new HashMap<>());
            }
            sortPlays.get(genres[i]).put(i, plays[i]);
        }
        List<Map.Entry<String, Integer>> sortedG = new LinkedList<>(sortGenres.entrySet());
        sortedG.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));
        for (Map.Entry<String, Integer> g : sortedG) {
            List<Map.Entry<Integer, Integer>> sortedP = new LinkedList<>(sortPlays.get(g.getKey()).entrySet());
            sortedP.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));
            int cnt = 0;
            for (Map.Entry<Integer, Integer> p : sortedP) {
                cnt++;
                answer.add(p.getKey());
                if (cnt == 2) break;
            }
        }
        
        
        return answer;
    }
}