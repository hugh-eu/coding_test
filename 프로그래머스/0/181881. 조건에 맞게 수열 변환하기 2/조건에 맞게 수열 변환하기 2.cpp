#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] >= 50 && arr[i] % 2 == 0) {
                if (arr[i] == arr[i] / 2)
                    ++cnt;
                arr[i] = arr[i] / 2;
            }
            else if (arr[i] < 50 && arr[i] % 2 == 1) {
                if (arr[i] == arr[i] * 2 + 1)
                    ++cnt;
                arr[i] = arr[i] * 2 + 1;
            }
            else
                ++cnt;
        }
        if (cnt == arr.size())
            return answer;
        ++answer;
    }
}