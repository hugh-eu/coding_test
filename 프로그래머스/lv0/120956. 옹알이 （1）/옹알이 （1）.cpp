#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> pos = {"aya", "ye", "woo", "ma"};
    for (string b : babbling) {
        int cnt = 0;
        for (string p : pos) {
            if (b.find(p) != string::npos) cnt += p.size();
        }
        if (cnt == b.size()) answer++;
    }

    return answer;
}