#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> sides) {
    int max = *max_element(sides.begin(), sides.end());
    if (accumulate(sides.begin(), sides.end(), 0) - max > max) {
        return 1;
    }
    return 2;
}