#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compareTotal(const pair<string, pair<int, vector<pair<int, int>>>> &a, const pair<string, pair<int, vector<pair<int, int>>>> &b) {
    return a.second.first > b.second.first;
}

bool compareEach(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, pair<int, vector<pair<int, int>>>> mapListing;
    for (int i = 0; i < genres.size(); i++) {
        mapListing[genres[i]].first += plays[i];
        mapListing[genres[i]].second.push_back(make_pair(i, plays[i]));
    }

    vector<pair<string, pair<int, vector<pair<int, int>>>>> vecListing(mapListing.begin(), mapListing.end());
    sort(vecListing.begin(), vecListing.end(), compareTotal);

    for (auto p1 : vecListing) {
        sort(p1.second.second.begin(), p1.second.second.end(), compareEach);
        int cnt = 0;
        for (pair<int, int> p2 : p1.second.second) {
            answer.push_back(p2.first);
            cnt++;
            if (cnt == 2) break;
        }
    }

    return answer;
}