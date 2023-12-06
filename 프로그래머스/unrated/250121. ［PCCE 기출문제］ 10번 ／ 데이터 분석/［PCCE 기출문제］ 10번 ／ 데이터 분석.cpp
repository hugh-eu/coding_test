#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmpIdx = -1;

bool compare(vector<int> &v1, vector<int> &v2) {
    return v1[cmpIdx] < v2[cmpIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<string> idx = {"code", "date", "maximum", "remain"};
    
    cmpIdx = find(idx.begin(), idx.end(), ext) - idx.begin();
    sort(data.begin(), data.end(), compare);
    for (vector<int> v : data) {
        if (v[cmpIdx] < val_ext) answer.push_back(v);
        else break;
    }
    
    cmpIdx = find(idx.begin(), idx.end(), sort_by) - idx.begin();
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}