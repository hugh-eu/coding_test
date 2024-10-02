#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int min_range = 1;
    int max_range = *max_element(diffs.begin(), diffs.end());

    while (min_range < max_range) {
        int target = (min_range + max_range) / 2;
        long long duration = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] <= target) duration += times[i];
            else duration += (times[i-1] + times[i]) * (diffs[i] - target) + times[i];
        }
        if (duration <= limit) max_range = target;
        else min_range = target + 1;
    }
    
    return max_range;
}