class Solution {
    public int[] solution(String[] park, String[] routes) {
        int[] answer = new int[2];

        boolean sFlag = false;
        for (int i = 0; i < park.length; i++) {
            for (int j = 0; j < park[i].length(); j++) {
                if (park[i].charAt(j) == 'S') {
                    answer[0] = i;
                    answer[1] = j;
                    sFlag = true;
                    break;
                }
            }
            if (sFlag) break;
        }

        for (String route : routes) {
            String op = route.split(" ")[0];
            int n = Integer.parseInt(route.split(" ")[1]);
            switch (op){
                case "N":
                    for (int i = 1; i <= n; i++) {
                        if (answer[0] - i < 0 || park[answer[0] - i].charAt(answer[1]) == 'X') break;
                        if (i == n) answer[0] -= n;
                    }
                    break;
                case "S":
                    for (int i = 1; i <= n; i++) {
                        if (answer[0] + i == park.length || park[answer[0] + i].charAt(answer[1]) == 'X') break;
                        if (i == n) answer[0] += n;
                    }
                    break;
                case "W":
                    for (int i = 1; i <= n; i++) {
                        if (answer[1] - i < 0 || park[answer[0]].charAt(answer[1] - i) == 'X') break;
                        if (i == n) answer[1] -= n;
                    }
                    break;
                case "E":
                    for (int i = 1; i <= n; i++) {
                        if (answer[1] + i == park[answer[0]].length() || park[answer[0]].charAt(answer[1] + i) == 'X') break;
                        if (i == n) answer[1] += n;
                    }
                    break;
            }
        }

        return answer;
    }
}