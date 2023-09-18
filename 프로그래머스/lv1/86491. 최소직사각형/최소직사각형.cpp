#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0;
    int y = 0;
    for (vector<int> size : sizes) {
        if (size[0] > size[1]) {
            if (size[0] > x) x = size[0];
            if (size[1] > y) y = size[1];
        } else {
            if (size[0] > y) y = size[0];
            if (size[1] > x) x = size[1];
        }
    }
    
    return x * y;
}