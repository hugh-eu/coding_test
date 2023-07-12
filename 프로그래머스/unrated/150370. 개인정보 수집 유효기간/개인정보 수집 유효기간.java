import java.util.*;

class Solution {
    public ArrayList<Integer> solution(String today, String[] terms, String[] privacies) {
        ArrayList<Integer> answer = new ArrayList<>();

        int yToday = Integer.parseInt(today.split("\\.")[0]);
        int mToday = Integer.parseInt(today.split("\\.")[1]);
        int dToday = Integer.parseInt(today.split("\\.")[2]);

        HashMap<String, Integer> termsMap = new HashMap<>();
        for (String t : terms) {
            termsMap.put(t.split(" ")[0], Integer.parseInt(t.split(" ")[1]));
        }

        for (int i = 0; i < privacies.length; i++) {
            int yPrivacy = Integer.parseInt(privacies[i].split(" ")[0].split("\\.")[0]);
            int mPrivacy = Integer.parseInt(privacies[i].split(" ")[0].split("\\.")[1]);
            int dPrivacy = Integer.parseInt(privacies[i].split(" ")[0].split("\\.")[2]);

            mPrivacy += termsMap.get(privacies[i].split(" ")[1]) - 1;
            dPrivacy += 27;

            mPrivacy += dPrivacy / 28;
            dPrivacy %= 28;
            if (dPrivacy == 0) {
                mPrivacy--;
                dPrivacy = 28;
            }
            yPrivacy += mPrivacy / 12;
            mPrivacy %= 12;
            if (mPrivacy == 0) {
                yPrivacy--;
                mPrivacy = 12;
            }

            if (yToday > yPrivacy) {
                answer.add(i + 1);
            } else if (yToday == yPrivacy) {
                if (mToday > mPrivacy) {
                    answer.add(i + 1);
                } else if (mToday == mPrivacy) {
                    if (dToday > dPrivacy) {
                        answer.add(i + 1);
                    }
                }
            }
        }

        return answer;
    }
}