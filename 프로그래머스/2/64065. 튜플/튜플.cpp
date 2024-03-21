#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

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

bool compare(vector<int> &a, vector<int> &b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    s = s.substr(2, s.size() - 4);

    vector<vector<string>> vvs;
    for (string &str : split(s, "},{")) vvs.push_back(split(str, ","));

    vector<vector<int>> vvi;
    for (vector<string> &v : vvs) {
        vector<int> vi;
        for (string &s : v) vi.push_back(stoi(s));
        vvi.push_back(vi);
    }

    sort(vvi.begin(), vvi.end(), compare);
    
    int prevSum = 0;
    for (vector<int> &vi : vvi) {
        int sum = accumulate(vi.begin(), vi.end(), 0);
        answer.push_back(sum - prevSum);
        prevSum = sum;
    }
        
    return answer;
}