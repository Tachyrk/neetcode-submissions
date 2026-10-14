#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.reserve(asteroids.size());

        for (int ast : asteroids) {
            bool alive = true;

            // 嚴格保證：只有當棧頂向右 (>0) 且當前向左 (<0) 時才會發生碰撞
            while (alive && ast < 0 && !ans.empty() && ans.back() > 0) {
                if (ans.back() < -ast) {
                    ans.pop_back(); // 棧頂較小，棧頂爆，當前繼續撞
                } else if (ans.back() == -ast) {
                    ans.pop_back(); // 兩者同大，同歸於盡
                    alive = false;
                } else {
                    alive = false;  // 棧頂較大，當前爆
                }
            }

            // 若當前小行星存活（例如：原本就向右、撞贏所有向右者、或前方全為向左者）
            if (alive) {
                ans.push_back(ast);
            }
        }

        return ans;
    }
};