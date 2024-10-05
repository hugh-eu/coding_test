#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second == b.second ? a.first > b.first : a.second > b.second;
}

int solution(int a, int b, int c, int d) {
    map<int, int> map_cnt_nums;
    for (int i : {a, b, c, d}) ++map_cnt_nums[i];
    vector<pair<int, int>> vec_cnt_nums(map_cnt_nums.begin(), map_cnt_nums.end());
    sort(vec_cnt_nums.begin(), vec_cnt_nums.end(), compare);
    
    if (vec_cnt_nums.size() == 1) {
        return 1111 * vec_cnt_nums[0].first;
    } else if (vec_cnt_nums.size() == 2) {
        if (vec_cnt_nums[0].second != vec_cnt_nums[1].second) {
            return pow(vec_cnt_nums[0].first * 10 + vec_cnt_nums[1].first, 2);
        } else {
            return (vec_cnt_nums[0].first + vec_cnt_nums[1].first) * abs(vec_cnt_nums[0].first - vec_cnt_nums[1].first);
        }
    } else if (vec_cnt_nums.size() == 3) {
        return vec_cnt_nums[1].first * vec_cnt_nums[2].first;
    } else {
        return vec_cnt_nums[3].first;
    }
}