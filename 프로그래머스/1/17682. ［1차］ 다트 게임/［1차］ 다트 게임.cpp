#include <cmath>
#include <string>
#include <vector>
#include <cctype>
#include <numeric>

using namespace std;

int solution(string dartResult) {
    vector<int> scores;
    int idx = -1;
    string s = "";

    for (char c : dartResult) {
        if (isdigit(c)) {
            s += c;
            continue;
        } else {
            if (c == 'S' || c == 'D'|| c == 'T') {
                scores.push_back(pow(stoi(s), c == 'S' ? 1 : c == 'D' ? 2 : 3));
                idx++;
                s = "";
            } else {
                scores[idx] *= c == '*' ? 2 : -1;
                if (c == '*' && idx > 0) scores[idx - 1] *= 2;
            }
        }
    }

    return accumulate(scores.begin(), scores.end(), 0);
}