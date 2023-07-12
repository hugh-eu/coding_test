class Solution {
    public int[] solution(int e, int[] starts) {
        int[] answer = new int[starts.length];

        int minStart = 5000001;
        for (int i = 0; i < starts.length; i++) {
            if (starts[i] < minStart) minStart = starts[i];
        }

//        int[] arrNumAppear = new int[e - minStart + 1];
//        for (int i = minStart; i <= e; i++) {
//            int sqrtI = (int)Math.sqrt(i);
//            int cntAppear = 0;
//            for (int j = 1; j <= sqrtI; j++) {
//                if (i % j == 0) cntAppear += 2;
//            }
//            if (Math.pow(sqrtI, 2) == i) cntAppear--;
//            arrNumAppear[arrNumAppear.length - (e - i) - 1] = cntAppear;
//        }

//        int[] arrMaxAppearNum = new int[e - minStart + 1];
//        int max = 0;
//        int maxAppearNum = -1;
//        for (int i = e; i >= minStart; i--) {
//            int numAppear = arrNumAppear[arrNumAppear.length - (e - i) - 1];
//            if (max <= numAppear) {
//                max = numAppear;
//                maxAppearNum = i;
//            }
//            arrMaxAppearNum[arrMaxAppearNum.length - (e - i) - 1] = maxAppearNum;
//        }

        int[] arrNumAppear = new int[e + 1];
        for (int i = 1; i <= e; i++) {
            for (int j = i; j <= e; j += i) {
                arrNumAppear[j]++;
            }
        }

        int[] arrMaxAppearNum = new int[e - minStart + 1];
        int max = 0;
        int maxAppearNum = -1;
        for (int i = e; i >= minStart; i--) {
            int numAppear = arrNumAppear[i];
            if (max <= numAppear) {
                max = numAppear;
                maxAppearNum = i;
            }
            arrMaxAppearNum[arrMaxAppearNum.length - (e - i) - 1] = maxAppearNum;
        }

        for (int i = 0; i < starts.length; i++) {
            answer[i] = arrMaxAppearNum[arrMaxAppearNum.length - (e - starts[i]) - 1];
        }

        return answer;
    }
}