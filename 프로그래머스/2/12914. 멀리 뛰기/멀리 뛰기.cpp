#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> cases = {1, 2};
    
    if (n > 2) {
        for (int i = 2; i < n; ++i) {
            cases.push_back((cases[i-1] + cases[i-2]) % 1234567);
        }
    }
    
    return cases[n-1];
}