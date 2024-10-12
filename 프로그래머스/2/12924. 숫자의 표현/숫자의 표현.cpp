#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n / 2; ++i) {
        int sum = 0;
        int j = i;
        while (sum < n) {
            sum += j;
            ++j;
        }
        if (sum == n) ++answer;
    }
    ++answer;
    
    return answer;
}