#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i : money) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }

    return dp[n];
}