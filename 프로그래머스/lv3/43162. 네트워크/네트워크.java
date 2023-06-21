class Solution {
    private int[] networks;

    private int[][] computers;

    public void dfs(int com) {
        for(int i = 0; i < networks.length; i++) {
            if (networks[i] == 0 && computers[com][i] == 1) {
                networks[i] = 1;
                dfs(i);
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
                dfs(i);
                answer++;
            }
        }

        return answer;
    }
}