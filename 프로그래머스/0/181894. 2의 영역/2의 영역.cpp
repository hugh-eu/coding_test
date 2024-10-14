#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (find(arr.begin(), arr.end(), 2) != arr.end()) {
        auto min_addr = find(arr.begin(), arr.end(), 2);
        auto max_addr = min_addr;
        
        while (find(max_addr + 1, arr.end(), 2) != arr.end()) {
            max_addr = find(max_addr + 1, arr.end(), 2);
        }

        return vector<int>(min_addr, max_addr + 1);
    }
    else
        return vector<int>(1, -1);
}