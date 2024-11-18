#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    for (int i = 1; i < words.size(); ++i) {
        bool wrong_condition1 = 
            words[i-1].back() != words[i].front();
        bool wrong_condition2 = 
            find(words.begin(), words.end(), words[i]) - words.begin() != i;
        if (wrong_condition1 || wrong_condition2) {
            return {i % n + 1, i / n + 1};
        }
    }
    return {0, 0};
}