#include <vector>

using namespace std;

int solution(int n) {
    vector<int> fib = {0, 1};
    for (int i = 2; i <= n; ++i) {
        fib.push_back((fib[i-1] + fib[i-2]) % 1234567);
    }
    return fib.back();
}