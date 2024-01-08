#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        int decimal1 = arr1[i];
        int decimal2 = arr2[i];
        int binary1;
        int binary2;
        string map = "";

        for (int j = 0; j < n; j++) {
            if (decimal1 == 1) {
                binary1 = 1;
                decimal1 = 0;
            } else {
                binary1 = decimal1 % 2;
                decimal1 /= 2;
            }
            if (decimal2 == 1) {
                binary2 = 1;
                decimal2 = 0;
            } else {
                binary2 = decimal2 % 2;
                decimal2 /= 2;
            }
            if (binary1 == 0 && binary2 == 0) map += ' ';
            else map += '#';
        }
        reverse(map.begin(), map.end());
        answer.push_back(map);
    }

    return answer;
}