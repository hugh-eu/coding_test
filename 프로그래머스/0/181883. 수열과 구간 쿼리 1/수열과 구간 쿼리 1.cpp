#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (vector<int> v : queries) {
        for (int i = v[0]; i <= v[1]; ++i) {
            ++arr[i];
        }
    }
    return arr;
}