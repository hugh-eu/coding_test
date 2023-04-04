class Solution {
    public int solution(String[][] book_time) {
        int answer = 0;
        
        int cnt = 0;

        for (int i = 0; i < 1440; i++) {
            for (String[] book : book_time) {
                if (Integer.parseInt(book[1].split(":")[0]) * 60 + Integer.parseInt(book[1].split(":")[1]) + 10 == i) {
                    cnt--;
                }

            }
            for (String[] book : book_time) {
                if (Integer.parseInt(book[0].split(":")[0]) * 60 + Integer.parseInt(book[0].split(":")[1]) == i) {
                    cnt++;
                }
                if (cnt > answer) answer = cnt;
            }
        }
        
        return answer;
    }
}