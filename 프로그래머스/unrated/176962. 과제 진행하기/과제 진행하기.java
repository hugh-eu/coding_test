import java.util.*;

class Solution {
    public ArrayList<String> solution(String[][] plans) {
        ArrayList<String> answer = new ArrayList<>();

        // 시간순 정렬
        Arrays.sort(plans, (o1, o2) -> (Integer.parseInt(o1[1].replace(":", "")) - Integer.parseInt(o2[1].replace(":", ""))));

        // 변수 초기화
        LinkedHashMap<String, Integer> studyMap = new LinkedHashMap<>();
        String studing = null;
        int timeRemain = -1;

        // 분단위 반복문, 현재 시간과 과제 시작 시간, 대기중인 과제의 관계
        // 첫 과제 시작 시간부터 모두 종료 될 때까지 1분 단위 반복
        int start = (Integer.parseInt(plans[0][1].split(":")[0]) * 60) + Integer.parseInt(plans[0][1].split(":")[1]);
        for (int i = start; i < 1440; i++) {
            // 진행중인 과제가 있을 경우
            if (timeRemain > 0) timeRemain--;
            // 과제 종료 시
            if (timeRemain == 0) {
                answer.add(studing);
                studyMap.remove(studing);
                // 대기 목록 확인 후 다음 진행
                if (studyMap.size() > 0) {
                    studing = (String)(studyMap.keySet().toArray()[studyMap.size() - 1]);
                    timeRemain = studyMap.get(studing);
                } else {
                    studing = null;
                    timeRemain = -1;
                }
            }
            // 과제 시작 시간
            for (String[] plan : plans) {
                if ((Integer.parseInt(plan[1].split(":")[0]) * 60) + Integer.parseInt(plan[1].split(":")[1]) == i) {
                    if (studing != null) studyMap.put(studing, timeRemain);
                    studing = plan[0];
                    timeRemain = Integer.parseInt(plan[2]);
                    studyMap.put(studing, timeRemain);
                }
            }
            // 모든 과제 종료 시
            if (answer.size() == plans.length) break;
            // 23:59 이후 새로 시작하는 과제가 없으므로 순서대로 종료
            if (i == 1439) {
                if (studing != null) {
                    answer.add(studing);
                    studyMap.remove(studing);
                }
                if (studyMap.size() > 0) for (int j = studyMap.size() - 1; j >= 0; j--) answer.add((String)studyMap.keySet().toArray()[j]);
            }
        }
        
        return answer;
        
    }
}