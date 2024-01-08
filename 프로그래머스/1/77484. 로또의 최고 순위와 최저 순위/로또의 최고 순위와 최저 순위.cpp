#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int unknown = 0;
    int correct = 0;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for (int i : lottos) {
        if (i == 0) unknown++;
        else {
            for (int j : win_nums) {
                if (i < j) break;
                if (i == j) {
                    correct++;
                    break;
                }
            }
        }
    }
    
    answer.push_back(7 - max(1, unknown + correct));
    answer.push_back(7 - max(1, correct));
    
    return answer;
}