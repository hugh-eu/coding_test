#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        budget -= d[i];
        if (budget < 0) return i;
    }
    return d.size();
}