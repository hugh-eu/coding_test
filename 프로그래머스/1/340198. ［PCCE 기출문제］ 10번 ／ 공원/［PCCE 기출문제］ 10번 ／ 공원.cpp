#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int max_length = 0;
    for (int i = 0; i < park.size(); i++) for (int j = 0; j < park[0].size(); j++) {
        if (park[i][j] == "-1") {
            bool stop_flag = false;
            int k = 1;
            while (i + k < park.size() && j + k < park[0].size()) {
                for (int l = 0; l <= k; l++) {
                    if (park[i+k-l][j+k] != "-1" || park[i+k][j+k-l] != "-1") {
                        stop_flag = true;
                        break;
                    }
                }
                if (stop_flag) break;
                k++;
            }
            if (k > max_length) max_length = k;
        }
    }
    
    sort(mats.rbegin(), mats.rend());
    for (int i : mats) {
        if (max_length >= i) return i;
    }
    return -1;
}