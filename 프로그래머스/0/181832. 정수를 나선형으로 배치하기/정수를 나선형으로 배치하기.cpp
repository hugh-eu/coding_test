#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    
    int x = 0;
    int y = 0;
    
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    
    for (int i = 1; i <= n*n; i++) {
        answer[y][x] = i;
        if (x < n-1-b && y == a) {
            x++;
            if (x == n-1-b) {
                a++;
            }
        }
        else if (x == n-1-b && y < n-1-c) {
            y++;
            if (y == n-1-c) {
                b++;
            }
        }
        else if (x > d && y == n-1-c) {
            x--;
            if (x == d) {
                c++;
            }
        }
        else if (x == d && y > a) {
            y--;
            if (y == a) {
                d++;
            }
        }
    }
    return answer;
}