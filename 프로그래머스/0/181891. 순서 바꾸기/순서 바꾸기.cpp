#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    num_list.insert(num_list.end(), num_list.begin(), num_list.begin() + n);
    return vector<int>(num_list.begin() + n, num_list.end());
}