#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    long long short_len = min(w, h);
    long long long_len = max(w, h);
    for (long long i = 1; i <= short_len; ++i) {
        answer -= (long long)(ceil(long_len * i / (double)short_len) - floor(long_len * (i - 1) / (double)short_len));
    }
    return answer;
}