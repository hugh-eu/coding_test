#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int product = 1;
    int sum = 0;
    
    for (int i : num_list) {
        product *= i;
        sum += i;
    }
    
    if (product < sum*sum) return 1;
    else if (product > sum*sum) return 0;
}