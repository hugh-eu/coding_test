class Solution
{
    public int solution(String s)
    {
        int answer = 0;

        for (int i = 0; i < s.length(); i++) {
            int cnt = 1;
            if (i != 0 && i != s.length() - 1) {
                for (int j = 1; j <= ((s.length() % 2 == 0 ? i < s.length() / 2 : i <= s.length() / 2) ? i : s.length() - 1 - i); j++) {
                    if (s.charAt(i - j) == s.charAt(i + j)) cnt += 2;
                    else break;
                }
            }
            if (cnt > answer) answer = cnt;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                int cnt = 2;
                if (i != 0 && i != s.length() - 2) {
                    for (int j = 1; j <= (i < s.length() / 2 ? i : s.length() - 2 - i); j++) {
                        if (s.charAt(i - j) == s.charAt(i + 1 + j)) cnt += 2;
                        else break;
                    }
                }
                if (cnt > answer) answer = cnt;
            }
        }

        return answer;

    }
}