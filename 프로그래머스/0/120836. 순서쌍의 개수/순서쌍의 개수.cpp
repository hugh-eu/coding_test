#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        for (int j = int(sqrt(n)); j <= n; j++) {
            if (i * j == n) {
                answer += 1;
            }
        }
    }
    return sqrt(n) == int(sqrt(n)) ? answer * 2 - 1 : answer * 2;
}