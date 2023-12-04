#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth = health;
    int castingTime = 0;

    queue<vector<int>> qAttacks;
    for (vector<int> v : attacks) qAttacks.push(v);

    for (int i = 0; i <= attacks[attacks.size() - 1][0]; i++) {
        if (i == qAttacks.front()[0]) {
            health -= qAttacks.front()[1];
            if (health <= 0) return -1;
            qAttacks.pop();
            castingTime = 0;
        } else {
            if (health < maxHealth) {
                health += bandage[1];
                castingTime++;
                if (castingTime == bandage[0]) {
                    health += bandage[2];
                    castingTime = 0;
                }
                if (health >= maxHealth) {
                    health = maxHealth;
                    castingTime = 0;
                }
            }
        }
    }

    return health;
}