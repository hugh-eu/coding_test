#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp_0_nm2(money.size());
    vector<int> dp_1_nm1(money.size());

    dp_0_nm2[0] = money[0];
    dp_0_nm2[1] = max(money[0], money[1]);
    for (int i = 2; i < money.size() - 1; i++) {
        dp_0_nm2[i] = max(dp_0_nm2[i - 2] + money[i], dp_0_nm2[i - 1]);
    }

    dp_1_nm1[0] = 0;
    dp_1_nm1[1] = money[1];
    for (int i = 2; i < money.size(); i++) {
        dp_1_nm1[i] = max(dp_1_nm1[i - 2] + money[i], dp_1_nm1[i - 1]);
    }

    return max(dp_0_nm2[money.size() - 2], dp_1_nm1[money.size() - 1]);
}