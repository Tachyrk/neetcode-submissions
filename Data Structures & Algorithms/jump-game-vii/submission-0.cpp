class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0') return false;

        queue<int> q;
        q.push(0);

        int farthest = 0; // 記錄目前已經探索過的最遠下標

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return true;

            // 核心優化：避開已經探索過的區域，直接從 farthest + 1 開始掃
            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;
                    q.push(j);
                }
            }

            // 更新已覆蓋的最遠邊界
            farthest = max(farthest, end);
        }

        return false;
    }
};