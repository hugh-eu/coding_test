#include <string>
#include <vector>

using namespace std;

bool check(long long i) {
    if (i % 5 == 2)
        return false;
    else if (i < 5)
        return true;
    return check(i / 5);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    for (long long i = l - 1; i < r; ++i) {
        if (check(i))
            ++answer;
    }
    
    return answer;
}