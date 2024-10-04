#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (vector<int> v : queries) {
        vector<int> sliced_arr(arr.begin()+v[0], arr.begin()+v[1]+1);
        sort(sliced_arr.begin(), sliced_arr.end());
        for (int i = 0; i < sliced_arr.size(); ++i) {
            if (sliced_arr[i] > v[2]) {
                answer.push_back(sliced_arr[i]);
                break;
            }
            if (i == sliced_arr.size()-1) answer.push_back(-1);
        }
    }
    
    return answer;
}