import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int m, int n, int startX, int startY, int[][] balls) {
        ArrayList<Integer> answer = new ArrayList<>();

        for (int[] b : balls) {
            int minDis = 25000000;
            if (startY != b[1]) {
                if (startX != m && b[0] != m) {
                    if (minDis > Math.pow(m + (m - startX) - b[0], 2) + Math.pow(startY - b[1], 2))
                        minDis = (int)(Math.pow(m + (m - startX) - b[0], 2) + Math.pow(startY - b[1], 2));
                }
                if (startX != 0 && b[0] != 0) {
                    if (minDis > Math.pow(startX + b[0], 2) + Math.pow(startY - b[1], 2))
                        minDis = (int)(Math.pow(startX + b[0], 2) + Math.pow(startY - b[1], 2));
                }
            } else {
                if (startX < b[0] && startX != 0) {
                    if (minDis > Math.pow(startX + b[0], 2))
                        minDis = (int)(Math.pow(startX + b[0], 2));
                }
                else if (startX > b[0] && startX != m) {
                    if (minDis > Math.pow((m - startX) + (m - b[0]), 2))
                        minDis = (int)(Math.pow((m - startX) + (m - b[0]), 2));
                }
            }
            if (startX != b[0]) {
                if (startY != n && b[1] != n) {
                    if (minDis > Math.pow(startX - b[0], 2) + Math.pow(n + (n - startY) - b[1], 2))
                        minDis = (int)(Math.pow(startX - b[0], 2) + Math.pow(n + (n - startY) - b[1], 2));
                }
                if (startY != 0 && b[1] != 0) {
                    if (minDis > Math.pow(startX - b[0], 2) + Math.pow(startY + b[1], 2))
                        minDis = (int)(Math.pow(startX - b[0], 2) + Math.pow(startY + b[1], 2));
                }
            } else {
                if (startY < b[1] && startY != 0) {
                    if (minDis > Math.pow(startY + b[1], 2))
                        minDis = (int)(Math.pow(startY + b[1], 2));
                }
                else if (startY > b[1] && startY != n) {
                    if (minDis > Math.pow((n - startY) + (n - b[1]), 2))
                        minDis = (int)(Math.pow((n - startY) + (n - b[1]), 2));
                }
            }

            if ((double)startY / startX == (double)b[1] / b[0]) {
                if (startX < b[0]) {
                    if (minDis > Math.pow(startX + b[0], 2) + Math.pow(startY + b[1], 2))
                        minDis = (int)(Math.pow(startX + b[0], 2) + Math.pow(startY + b[1], 2));

                }
            }
            if ((double)startY / (m - startX) == (double)b[1] / (m - b[0])) {
                if (startX > b[0]) {
                    if (minDis > Math.pow((m - startX) + (m - b[0]), 2) + Math.pow(startY + b[1], 2))
                        minDis = (int)(Math.pow((m - startX) + (m - b[0]), 2) + Math.pow(startY + b[1], 2));

                }
            }
            if ((double)(n - startY) / startX == (double)(n - b[1]) / b[0]) {
                if (startX < b[0]) {
                    if (minDis > Math.pow(startX + b[0], 2) + Math.pow((n - startY) + (n - b[1]), 2))
                        minDis = (int)(Math.pow(startX + b[0], 2) + Math.pow((n - startY) + (n - b[1]), 2));

                }
            }
            if ((double)(n - startY) / (m - startX) == (double)(n - b[1]) / (m - b[0])) {
                if (startX < b[0]) {
                    if (minDis > Math.pow((m - startX) + (m - b[0]), 2) + Math.pow((n - startY) + (n - b[1]), 2))
                        minDis = (int)(Math.pow((m - startX) + (m - b[0]), 2) + Math.pow((n - startY) + (n - b[1]), 2));

                }
            }

            answer.add(minDis);

        }
        
        return answer;
    }
}