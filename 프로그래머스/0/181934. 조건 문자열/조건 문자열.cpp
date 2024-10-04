#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if (ineq == "<" ? eq == "=" ? n <= m : n < m : eq == "=" ? n >= m : n > m) return 1;
    return 0;
}