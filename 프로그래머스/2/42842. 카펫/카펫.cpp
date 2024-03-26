#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {    
    for (int i = 1; i <= yellow; i++) for (int j = i; j > 0; j--) {
        if (i * j == yellow && (i + j + 2) * 2 == brown) {
            return vector<int>({i + 2, j + 2});
        }
    }
}