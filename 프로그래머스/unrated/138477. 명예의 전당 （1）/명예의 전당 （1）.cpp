#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    vector<int> hof;
    for (int s : score) {
        hof.push_back(s);
        sort(hof.rbegin(), hof.rend());
        answer.push_back(hof.size() >= k ? hof[k - 1] : hof[hof.size() - 1]);
    }

    return answer;
}