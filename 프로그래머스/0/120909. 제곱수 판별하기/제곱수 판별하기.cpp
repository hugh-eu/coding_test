#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    if (sqrt(n) == (int)(sqrt(n))) return 1;
    return 2;
}