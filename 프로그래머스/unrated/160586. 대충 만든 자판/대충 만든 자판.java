class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] answer = new int[targets.length];

        for (int i = 0; i < targets.length; i++) {
            // targets[i], 입력할 문자열
            boolean flagUnable = false;
            int cntTotal = 0;  // 해당 문자열의 입력을 위해 키를 누른 횟수
            for (int j = 0; j < targets[i].length(); j++) {
                char target = targets[i].charAt(j);  // targets[i]의 각 문자, 입력할 문자
                boolean flagLoop = true;
                int cntTouch = 0;  // target 입력을 위해 누른 횟수 - 1
                while (flagLoop) {
                    int cntOoB = 0;  // 키맵에 남은 문자 확인용
                    // 각 키맵 j번째 문자와 target을 비교하여 횟수 확인
                    for (int k = 0; k < keymap.length; k++) {
                        if (keymap[k].length() > cntTouch) {
                            // 타겟과 누른 문자의 일치여부 확인
                            if (target == keymap[k].charAt(cntTouch)) {
                                cntTotal += cntTouch + 1;
                                flagLoop = false;
                                break;  // 일치시 문자열 총횟수에 합, 다음 문자로
                            }
                        } else cntOoB++;  // 키맵의 길이확인
                        // 키맵 모두 확인, 문자열작성 불가
                        if (cntOoB == keymap.length) {
                            flagUnable = true;
                            cntTotal = -1;
                            flagLoop = false;
                        }
                    }
                    cntTouch++;
                }
                if (flagUnable) break;
            }
            answer[i] = cntTotal;  // 결과 저장
        }

        return answer;
    }
}