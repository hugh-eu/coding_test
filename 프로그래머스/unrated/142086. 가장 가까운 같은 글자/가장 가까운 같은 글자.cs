using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string s) {
        int[] answer = new int[s.Length];

        Dictionary<char, int> dictCharIdx = new Dictionary<char, int>();
        for (int i = 0; i < s.Length; i++) {
            if (dictCharIdx.ContainsKey(s[i])) {
                answer[i] = i - dictCharIdx[s[i]];
                dictCharIdx[s[i]] = i;
            } else {
                answer[i] = -1;
                dictCharIdx.Add(s[i], i);
            }
        }

        return answer;
    }
}