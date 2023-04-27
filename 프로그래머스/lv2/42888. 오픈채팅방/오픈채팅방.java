import java.util.*;

class Solution {
    public ArrayList<String> solution(String[] record) {
        ArrayList<String> answer = new ArrayList<>();
        Map<String, String> idNick = new HashMap<>();
        
        for (String r : record) {
            if (r.split(" ")[0].equals("Enter") || r.split(" ")[0].equals("Change")) idNick.put(r.split(" ")[1], r.split(" ")[2]);
        }
        
        for (String r : record) {
            if (r.split(" ")[0].equals("Enter")) answer.add(idNick.get(r.split(" ")[1]) + "님이 들어왔습니다.");
            else if (r.split(" ")[0].equals("Leave")) answer.add(idNick.get(r.split(" ")[1]) + "님이 나갔습니다.");
        }
            
        return answer;

    }
}