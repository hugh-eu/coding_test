#include <bitset>

using namespace std;

int solution(int n) {
    int i = bitset<20>(n).count();
    while (bitset<20>(++n).count() != i);
    return n;
}