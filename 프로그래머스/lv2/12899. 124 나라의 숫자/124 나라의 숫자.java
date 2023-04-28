class Solution {
    public String solution(int n) {
        StringBuilder answer = new StringBuilder();

//        int intAns, intJm1, intJ;
//        for (int i = 1; i <= n; i++) {
//            if (answer.toString().equals("")) answer.append(i);
//            else if (answer.length() == 1) {
//                intAns = Integer.parseInt(answer.toString());
//                answer.replace(0, 1, Integer.toString(intAns == 2 ? intAns + 2 : intAns + 1));
//                if (answer.toString().equals("5")) answer.replace(0,1,"11");
//            }
//            else {
//                for (int j = answer.length() - 1; j >= 0; j--) {
//                    if (j == answer.length() - 1) {
//                        intJ = Integer.parseInt(answer.substring(j, j + 1));
//                        answer.replace(j, j + 1, Integer.toString(intJ == 2 ? intJ + 2 : intJ + 1));
//                    }
//                    if (answer.substring(j, j + 1).toString().equals("5")) {
//                        if (j == 0) {
//                            answer.replace(0, 1, "11");
//                        } else {
//                            intJm1 = Integer.parseInt(answer.substring(j - 1, j));
//                            answer.replace(j - 1, j, Integer.toString(intJm1 == 2 ? intJm1 + 2 : intJm1 + 1));
//                            answer.replace(j, j + 1, "1");
//                        }
//                    } else break;
//                }
//            }
//        }

        int remainder;
        while (n > 0) {
            remainder = n % 3;
            if (remainder == 0) {
                answer.insert(0, "4");
                n = n / 3 - 1;
            } else {
                answer.insert(0, remainder);
                n = n / 3;
            }
        }
        
        return answer.toString();
    }
}