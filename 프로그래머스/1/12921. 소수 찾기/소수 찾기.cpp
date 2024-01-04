#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
    vector<bool> v(n, true);

    for (int i = 2; i <= sqrt(n); i++) {
        if (v[i]) {
            int j = 2;
            while (i * j <= n) v[i * j++] = false;
        }
    }

    return count(v.begin() + 2, v.end() + 1, true);
}