class Solution {
    public String solution(String s, String skip, int index) {
        String answer = "";

        for (int i = 0; i < s.length(); i++) {
            int tempIndex = index;
            int j = 0;
            // 처리할 문자와 index 만큼 뒤의 문자 사이에 포함된 skip 수 만큼 index 증가
            while (j != tempIndex) {
                j++;
                if (skip.contains(String.valueOf((char)(97 + (((int)s.charAt(i) + j - 97) % 26))))) tempIndex++;  // ASCII
            }
            answer += (char)(97 + (((int)s.charAt(i) + tempIndex - 97) % 26));
        }

        return answer;
    }
}