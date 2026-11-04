class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qr, qd;

        // 記錄初始發言順位
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                qr.push(i);
            } else {
                qd.push(i);
            }
        }

        // 只要兩邊都還有人，就按順位對決
        while (!qr.empty() && !qd.empty()) {
            int r_idx = qr.front();
            int d_idx = qd.front();
            qr.pop();
            qd.pop();

            // 誰的索引小，誰先動手 Ban 掉對方
            // 存活者加上 n 進入下一輪排隊
            if (r_idx < d_idx) {
                qr.push(r_idx + n);
            } else {
                qd.push(d_idx + n);
            }
        }

        return qr.empty() ? "Dire" : "Radiant";
    }
};