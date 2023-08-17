#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> pos = {"aya", "ye", "woo", "ma"};
    for (string b : babbling) {
        bool flag = true;
        int length = 0;
        for (string p : pos) {
            if (b.find(p + p) != string::npos) {
                flag = false;
                break;
            }
            int pos = 0;
            while (b.find(p, pos) != string::npos) {
                pos = b.find(p, pos) + p.size();
                length += p.size();
            }
        }
        if (flag && b.size() == length) answer++;
    }
    
    return answer;
}