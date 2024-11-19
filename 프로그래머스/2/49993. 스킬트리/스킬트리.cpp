#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string &st : skill_trees) {
        vector<int> skill_idx;
        for (char &s : skill) {
            if (st.find(s) == string::npos) {
                skill_idx.push_back(-1);
            }
            else {
                skill_idx.push_back(st.find(s));
            }
        }
        int pre_idx;
        for (int i = 0; i < skill_idx.size(); ++i) {
            if (i == 0) {
                pre_idx = skill_idx[i];
            }
            else {
                if (pre_idx == -1) {
                    if (skill_idx[i] != -1) {
                        break;
                    }
                }
                else {
                    if (skill_idx[i] > pre_idx || skill_idx[i] == -1) {
                        pre_idx = skill_idx[i];
                    }
                    else {
                        break;
                    }
                }
            }
            if (i == skill_idx.size() - 1) {
                ++answer;
            }
        }
    }
    
    return answer;
}