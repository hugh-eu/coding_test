#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int cntX[10]{0,}, cntY[10]{0,};
    bool chkZero = true;

    for (char c : X) cntX[c - '0']++;
    for (char c : Y) cntY[c - '0']++;
    for (int i = 9; i >= 0; i--) {
        while (cntX[i]-- > 0 && cntY[i]-- > 0) {
            answer += to_string(i);
            if (chkZero && i > 0) chkZero = false;
        }
    }

    return answer.size() > 0 ? chkZero ? "0" : answer : "-1";
}