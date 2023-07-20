using System;

public class Solution {
    public int solution(string s) {
        int answer = 0;

        char x = ' ';
        int numX = 0, numOthers = 0;
        for (int i = 0; i < s.Length; i++) {
            if (x == ' ') {
                x = s[i];
                numX++;
            } else {
                if (x == s[i]) numX++;
                else numOthers++;
            }
            if (numX == numOthers) {
                answer++;
                x = ' ';
                numX = 0;
                numOthers = 0;
            } else if (i == s.Length - 1) answer++;
        }

        return answer;
    }
}
