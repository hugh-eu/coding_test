#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    vector<vector<int>> giftTable(friends.size(), vector<int>(friends.size()));
    vector<int> giftIndex(friends.size());
    vector<int> numOfGifts(friends.size());
    
    for (string gift : gifts) {
        vector<string> splitGift;
        istringstream iss(gift);
        string buffer;
        while (getline(iss, buffer, ' ')) splitGift.push_back(buffer);
        int i = find(friends.begin(), friends.end(), splitGift[0]) - friends.begin();
        int j = find(friends.begin(), friends.end(), splitGift[1]) - friends.begin();
        giftTable[i][j]++;
        giftIndex[i]++;
        giftIndex[j]--;
    }
    for (int i = 0; i < friends.size() - 1; i++) for (int j = i + 1; j < friends.size(); j++) {
        if (giftTable[i][j] > giftTable[j][i]) numOfGifts[i]++;
        else if (giftTable[i][j] < giftTable[j][i]) numOfGifts[j]++;
        else {
            if (giftIndex[i] > giftIndex[j]) numOfGifts[i]++;
            else if (giftIndex[i] < giftIndex[j]) numOfGifts[j]++;
        }
    }
    
    return *max_element(numOfGifts.begin(), numOfGifts.end());
}