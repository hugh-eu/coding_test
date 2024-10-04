#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (vector<int> &v : queries) iter_swap(arr.begin() + v.front(), arr.begin() + v.back());
    return arr;
}