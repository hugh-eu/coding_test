class Solution {
    fun solution(cards1: Array<String>, cards2: Array<String>, goal: Array<String>): String {
        var answer: String = "Yes"

        var c1 = cards1.toCollection(ArrayList<String>())
        var c2 = cards2.toCollection(ArrayList<String>())
        for (g in goal) {
            if (c1.size > 0 && c1[0].equals(g)) {
                c1.removeAt(0)
                continue
            } else if (c2.size > 0 && c2[0].equals(g)) {
                c2.removeAt(0)
                continue
            } else {
                answer = "No"
                break
            }
        }

        return answer
    }
}