#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    // bool flag = true;
    // while (flag && ingredient.size() >= 4) {
    //     flag = false;
    //     for (int i = 0; i < ingredient.size() - 3; i++) {
    //         if (ingredient[i] == 1 && ingredient[i + 1] == 2 && ingredient[i + 2] == 3 && ingredient[i + 3] == 1) {
    //             answer++;
    //             flag = true;
    //             ingredient.erase(ingredient.begin() + i, ingredient.begin() + i + 4);
    //             break;
    //         }
    //     }
    // }

    string strIngredient = "";
    for (int i : ingredient) strIngredient += to_string(i);
    int sIdx = 0;
    while (strIngredient.find("1231", sIdx) != string::npos) {
        answer++;
        int fIdx = strIngredient.find("1231", sIdx);
        strIngredient.erase(fIdx, 4);
        if (fIdx >= 3) sIdx = fIdx - 3;
    }

    return answer;
}