#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    if (n == 1) {
        return vector<int>(num_list.begin() + 0, num_list.begin() + slicer[1] + 1);
    } else if (n == 2) {
        return vector<int>(num_list.begin() + slicer[0], num_list.end());
    } else if (n == 3) {
        return vector<int>(num_list.begin() + slicer[0], num_list.begin() + slicer[1] + 1);
    } else if (n == 4) {
        vector<int> answer;
        for (int i = slicer[0]; i <= slicer[1]; i += slicer[2]) {
            answer.push_back(num_list[i]);
        }
        return answer;
    }
}