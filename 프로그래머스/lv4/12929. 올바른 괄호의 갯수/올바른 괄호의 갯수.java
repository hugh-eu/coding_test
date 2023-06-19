class Solution {
    static int answer = 0;
    
    public int solution(int n) {
        int op = n;
        int cl = 0;
        app(op, cl);
        
        return answer;
    }
    
    public static void app(int op, int cl) {
        if (op == 0 && cl == 0) answer++;
        else {
            int opTemp = op;
            int clTemp = cl;
            for (int i = 0; i < 2; i++) {
                if (i == 0 && op > 0) {
                    op--;
                    cl++;
                } else if (i == 1 && cl > 0) {
                    cl--;
                } else {
                    continue;
                }
                app(op, cl);
                op = opTemp;
                cl = clTemp;
            }
        }
    }
}