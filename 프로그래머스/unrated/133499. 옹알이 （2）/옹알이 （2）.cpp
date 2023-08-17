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
            int position = 0;
            while (b.find(p, position) != string::npos) {
                length += p.size();
                position = b.find(p, position) + p.size();
            }
        }
        if (flag && b.size() == length) answer++;
    }
    
    return answer;
}