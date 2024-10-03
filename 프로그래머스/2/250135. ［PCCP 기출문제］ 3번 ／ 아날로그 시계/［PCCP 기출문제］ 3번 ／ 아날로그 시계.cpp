#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int start_sec = 3600 * h1 + 60 * m1 + s1;
    int end_sec = 3600 * h2 + 60 * m2 + s2;
    
    for (int i = start_sec; i <= end_sec; ++i) {
        float h_pos = fmod((i / 720.0), 60);
        float m_pos = fmod((i / 60.0), 60);
        float s_pos = fmod(i, 60);
        
        if (i == start_sec) {
            if (h_pos == s_pos) ++answer;
            if (m_pos == s_pos) ++answer;
        }
        if (h_pos == m_pos && m_pos == s_pos) --answer;
        if (i != end_sec) {
            if (s_pos < h_pos && h_pos < s_pos + 1) ++answer;
            if (s_pos < m_pos && m_pos < s_pos + 1) ++answer;
        }
    }
    
    return answer;
}