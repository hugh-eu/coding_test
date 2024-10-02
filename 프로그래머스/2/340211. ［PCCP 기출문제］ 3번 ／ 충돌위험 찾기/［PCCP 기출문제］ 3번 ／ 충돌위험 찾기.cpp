#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<pair<vector<int>, int>> routes_sec;
    for (vector<int> &v : routes) routes_sec.push_back(make_pair(v, 0));
    
    bool flag = true;
    while (flag) {
        flag = false;
        map<vector<int>, int> pos;
        for (pair<vector<int>, int> &p : routes_sec) {
            if (p.first.size() >= 2) {
                flag = true;
                int pos_r = points[p.first[0]-1][0];
                int pos_c = points[p.first[0]-1][1];
                int goal_r = points[p.first[1]-1][0];
                int goal_c = points[p.first[1]-1][1];
                if (goal_r >= pos_r) {
                    pos_r += p.second;
                    if (pos_r > goal_r) {
                        if (goal_c >= pos_c) {
                            pos_c += pos_r - goal_r;
                        } else {
                            pos_c -= pos_r - goal_r;
                        }
                        pos_r = goal_r;
                    }
                } else {
                    pos_r -= p.second;
                    if (pos_r < goal_r) {
                        if (goal_c >= pos_c) {
                            pos_c += goal_r - pos_r;
                        } else {
                            pos_c -= goal_r - pos_r;
                        }
                        pos_r = goal_r;
                    }
                }
                pos[{pos_r, pos_c}]++;
                if (pos_r == goal_r && pos_c == goal_c) {
                    p.first.erase(p.first.begin());
                    p.second = 0;
                }
                p.second++;
            }
        }
        for (auto &iter : pos) {
            if (iter.second >= 2) answer++;
        }
    }
    
    return answer;
}