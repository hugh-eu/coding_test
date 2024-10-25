#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> group;
vector<bool> rule_1;
vector<bool> rule_2;
vector<bool> used;
int w_idx;

struct info {
    int start, end, cnt;
};

bool check_rule_1(string& sentence, info l_info, char c) {
    if (used[c - 'a'] == true) {
        return false;
    }
    if (l_info.start - 1 < 0 || l_info.end + 1 >= N) {
        return false;
    }
    if (islower(sentence[l_info.start - 1]) || islower(sentence[l_info.end + 1])) {
        return false;
    }

    int l_cnt = 0, u_cnt = 0;
    for (int i = l_info.start - 1; i <= l_info.end + 1; ++i) {
        char now = sentence[i];
        if (islower(now)) {
            if (now == c) {
                group[i] = w_idx;
                ++l_cnt;
                u_cnt = 0;
            }
            else {
                return false;
            }
        }
        else if (isupper(now)) {
            l_cnt = 0;
            ++u_cnt;
            if (rule_1[i] == true) {
                return false;
            }
            else {
                group[i] = w_idx;
                rule_1[i] = true;
            }
        }
        if (l_cnt > 1 || u_cnt > 1) {
            return false;
        }
    }
    ++w_idx;
    used[c - 'a'] = true;
    return true;
}

bool check_rule_2(string& sentence, info l_info, char c) {
    if (used[c - 'a'] == true) {
        return false;
    }
    if (l_info.end - l_info.start < 2) {
        return false;
    }
    group[l_info.start] = w_idx;
    group[l_info.end] = w_idx;
    for (int i = l_info.start + 1; i < l_info.end; ++i) {
        char now = sentence[i];
        if (isupper(now)) {
            if (rule_2[i] == true) {
                return false;
            }
            else {
                group[i] = w_idx;
                rule_2[i] = true;
            }
        }
    }
    ++w_idx;
    used[c - 'a'] = true;
    return true;
}

info get_char_info(string& sentence, char c) {
    int start = -1;
    int cnt = 0;
    int end = 0;
    for (int i = 0; i < N; ++i) {
        if (sentence[i] == c) {
            if (start < 0) {
                start = i;
            }
            ++cnt;
            end = i;
        }
    }
    return {start, end, cnt};
}

bool decrypting_possible(string &sentence) {
    vector<bool> check_chars(26);
    for (int i = 0; i < N; ++i) {
        char now = sentence[i];
        if (now == ' ') {
            return false;
        }
        if (group[i] == 0) {
            if (isupper(now)) {
                if (i + 1 >= N) {
                    group[i] = w_idx++;
                    continue;
                }
                char next = sentence[i + 1];
                if (isupper(next)) {
                    group[i] = w_idx++;
                }
                else if (islower(next)) {
                    info l_info = get_char_info(sentence, next);
                    if (l_info.cnt == 2) {
                        group[i] = w_idx++;
                    }
                    else {
                        if (check_rule_1(sentence, l_info, next) == false) {
                            return false;
                        }
                    }
                }
            }
            else if (islower(now)) {
                info l_info = get_char_info(sentence, now);
                if (l_info.cnt == 2) {
                    if (isupper(sentence[i + 1]) && rule_2[i + 1]) {
                        if (check_rule_1(sentence, l_info, now) == false) {
                            return false;
                        }
                    }
                    else {
                        if (check_rule_2(sentence, l_info, now) == false) {
                            return false;
                        }
                    }
                }
                else {
                    if (check_rule_1(sentence, l_info, now) == false) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

string make_answer(string &sentence) {
    int last_idx = 0;
    for (int i = 0; i < N; ++i) {
        if (isupper(sentence[i])) {
            last_idx = group[i];
            break;
        }
    }
    string answer = "";
    for (int i = 0; i < N; ++i) {
        char c = sentence[i];
        if (isupper(c)) {
            if (group[i] != last_idx) {
                answer += ' ';
            }

            answer += c;
            last_idx = group[i];
        }
    }
    return answer;
}

string solution(string sentence) {
    N = sentence.size();
    group = vector<int>(N);
    rule_1 = vector<bool>(N);
    rule_2 = vector<bool>(N);
    used = vector<bool>(26);
    w_idx = 1;

    bool result = decrypting_possible(sentence);

    if (!result) {
        return "invalid";
    }

    return make_answer(sentence);
}