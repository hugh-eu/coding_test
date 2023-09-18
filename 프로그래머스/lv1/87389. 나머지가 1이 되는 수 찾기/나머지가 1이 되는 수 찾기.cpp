#include <string>
#include <vector>

using namespace std;

int solution(int n) {    
    for (int i = 2; i < 1000000; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            if (n % i == 1) return i;
        }
    }
}