#include <string>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<vector<int>> &candidates, set<set<int>> &cases, set<int> c, int i) {
    if (i == candidates.size()) cases.insert(c);
    else {
        for (int j = 0; j < candidates[i].size(); ++j) {
            if (!c.count(candidates[i][j])) {
                c.insert(candidates[i][j]);
                dfs(candidates, cases, c, i+1);
                c.erase(candidates[i][j]);
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<int>> candidates;
    set<set<int>> cases;
    
    for (int i = 0; i < banned_id.size(); ++i) {
        vector<int> v;
        for (int j = 0; j < user_id.size(); ++j) {
            if (user_id[j].size() == banned_id[i].size()) {
                for (int k = 0; k < user_id[j].size(); ++k) {
                    if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]) break;
                    if (k == user_id[j].size()-1) v.push_back(j);
                }
            }
        }
        candidates.push_back(v);
    }
    
    dfs(candidates, cases, set<int>(), 0);
    
    return cases.size();
}