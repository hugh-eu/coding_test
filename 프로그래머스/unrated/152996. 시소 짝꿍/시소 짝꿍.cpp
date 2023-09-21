#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    long long sameWeight = 0;
    long long duplication = 0;

    for (long long i = 0; i < weights.size(); i++) {
        for (long long j = i + 1; j < weights.size(); j++) {
            if (weights[i] == weights[j]) {
                sameWeight++;
                break;
            }
            else if (sameWeight > 0) {
                if (weights[i] == weights[j] / 2.0 || weights[i] == weights[j] * 2 / 3.0 || weights[i] == weights[j] * 3 / 4.0) duplication++;
                if (j == weights.size() - 1) {
                    for (long long k = sameWeight; k >= 1; k--) answer += k;
                    answer += duplication * (sameWeight + 1);
                    sameWeight = 0;
                    duplication = 0;
                }
            }
            else if (weights[i] == weights[j] / 2.0 || weights[i] == weights[j] * 2 / 3.0 || weights[i] == weights[j] * 3 / 4.0) answer++;
        }
        if (i == weights.size() - 1 && sameWeight > 0) for (long long k = sameWeight; k >= 1; k--) answer += k;
    }

    return answer;
}