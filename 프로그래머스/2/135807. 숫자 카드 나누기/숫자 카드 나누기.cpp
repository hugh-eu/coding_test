#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    bool flag = true;
    int i = 1;
    while (flag) {
        if (i == arrayA[0]) break;
        if (arrayA[0] % i == 0) {
            int divisor = arrayA[0] / i;
            for (int j = 0; j < arrayA.size(); j++) {
                if (arrayA[j] % divisor != 0) break;
                if (j == arrayA.size() - 1) {
                    for (int k = 0; k < arrayB.size(); k++) {
                        if (arrayB[k] % divisor == 0) break;
                        if (k == arrayB.size() - 1) {
                            answer = divisor;
                            flag = false;
                        }
                    }
                }
            }
        }
        i++;
    }
    flag = true;
    i = 1;
    while (flag) {
        if (i == arrayB[0]) break;
        if (arrayB[0] % i == 0) {
            int divisor = arrayB[0] / i;
            for (int j = 0; j < arrayB.size(); j++) {
                if (arrayB[j] % divisor != 0) break;
                if (j == arrayB.size() - 1) {
                    for (int k = 0; k < arrayA.size(); k++) {
                        if (arrayA[k] % divisor == 0) break;
                        if (k == arrayA.size() - 1) {
                            if (divisor > answer) answer = divisor;
                            flag = false;
                        }
                    }
                }
            }
        }
        i++;
    }

    return answer;
}