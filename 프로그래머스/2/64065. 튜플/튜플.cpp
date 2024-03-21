#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<string> split(string &str, string dlim) {
    vector<string> result;
    
    int idx = 0;
    while (idx < str.size()) {
        int dlim_idx = str.find(dlim, idx);
        if (dlim_idx == -1) dlim_idx = str.size();
        if (dlim_idx - idx > 0) result.push_back(str.substr(idx, dlim_idx - idx));
        idx = dlim_idx + dlim.size();
    }
    
    return result;
}

bool compare(vector<string> &a, vector<string> &b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    s = s.substr(2, s.size() - 4);

    vector<vector<string>> vvs;
    for (string &str : split(s, "},{")) vvs.push_back(split(str, ","));

    sort(vvs.begin(), vvs.end(), compare);

    auto sumFunc = [](int sum, string &str) {
        return sum + stoi(str);
    };

    int prevSum = 0;
    for (vector<string> &vs : vvs) {
        int sum = accumulate(vs.begin(), vs.end(), 0, sumFunc);
        answer.push_back(sum - prevSum);
        prevSum = sum;
    }

    return answer;
}