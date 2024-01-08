#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10;
    int rightHand = 12;
    
    for (int i : numbers) {
        if (i == 1 || i == 4 || i == 7) {
            answer += 'L';
            leftHand = i;
        } else if (i == 3 || i == 6 || i == 9) {
            answer += 'R';
            rightHand = i;
        } else {
            if (i == 0) i = 11;
            int distL = (leftHand - 2) % 3 != 0 ? abs(i - (leftHand + 1)) / 3 + 1 : abs(i - leftHand) / 3;
            int distR = (rightHand - 2) % 3 != 0 ? abs(i - (rightHand - 1)) / 3 + 1 : abs(i - rightHand) / 3;
            if (distL > distR) {
                answer += 'R';
                rightHand = i;
            } else if (distL < distR) {
                answer += 'L';
                leftHand = i;
            } else {
                if (hand == "left") {
                    answer += 'L';
                    leftHand = i;
                } else {
                    answer += 'R';
                    rightHand = i;
                }
            }
        }
    }
    
    return answer;
}