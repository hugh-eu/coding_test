import java.util.*;

class Solution {
    private int[] networks;

    private int[][] computers;

    public void dfs(int com) {
        for (int i = 0; i < networks.length; i++) {
            if (networks[i] == 0 && computers[com][i] == 1) {
                networks[i] = 1;
                dfs(i);
            }
        }
    }

    public void bfs(int com) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(com);
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j = 0; j < networks.length; j++) {
                if (networks[j] == 0 && computers[i][j] == 1) {
                    networks[j] = 1;
                    q.offer(j);
                }
            }
        }
    }

    public int solution(int n, int[][] computers) {
        networks = new int[n];
        this.computers = computers;
        int answer = 0;
        for (int i = 0; i < networks.length; i++) {
            if (networks[i] == 0) {
                networks[i] = 1;
//                dfs(i);
                bfs(i);
                answer++;
            }
        }

        return answer;
    }
}