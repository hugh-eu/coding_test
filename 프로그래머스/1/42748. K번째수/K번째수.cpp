#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> v : commands) {
        vector<int> slice(array.begin() + v[0] - 1, array.begin() + v[1]);
        sort(slice.begin(), slice.end());
        answer.push_back(slice[v[2] - 1]);
    }
    
    return answer;
}