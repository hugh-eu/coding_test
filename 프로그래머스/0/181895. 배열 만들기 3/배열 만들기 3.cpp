#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> v1(arr.begin() + intervals[0][0], arr.begin() + intervals[0][1] + 1);
    vector<int> v2(arr.begin() + intervals[1][0], arr.begin() + intervals[1][1] + 1);
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}