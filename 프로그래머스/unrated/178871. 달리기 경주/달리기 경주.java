import java.util.*;

class Solution {
    private HashMap<String, Integer> idxMap;

    private String[] players;

    public void call(String name) {
        int idx = idxMap.get(name);

        idxMap.put(players[idx - 1], idx);
        idxMap.put(name, idx - 1);

        players[idx] = players[idx - 1];
        players[idx - 1] = name;
    }

    public String[] solution(String[] players, String[] callings) {
        idxMap = new HashMap<>();
        for (int i = 0; i < players.length; i++) idxMap.put(players[i], i);
        this.players = players;

        for (String name : callings) call(name);

        return this.players;
    }
}