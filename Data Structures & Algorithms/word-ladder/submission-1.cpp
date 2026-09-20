class Solution {
public:
    int caldistance(const string &a, const string &b){
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) ans++;
        }
        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 先找 endWord 的索引，若根本不存在直接回傳 0
        int endIdx = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                endIdx = i;
                break;
            }
        }
        if (endIdx == -1) return 0;

        // 將 beginWord 加到最後一個位置
        wordList.push_back(beginWord);
        int n = wordList.size();
        int startIdx = n - 1;

        // 用 index 建立相鄰表，完全省下 string 的 hash map 開銷
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (caldistance(wordList[i], wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // 權重為 1，一般 queue 的 BFS 保證第一次摸到就是最短步數
        queue<pair<int, int>> q; // {當前節點 index, 當前步數}
        vector<bool> visited(n, false);

        q.push({startIdx, 1});
        visited[startIdx] = true;

        while (!q.empty()) {
            auto [u, step] = q.front();
            q.pop();

            if (u == endIdx) return step;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, step + 1});
                }
            }
        }

        return 0;
    }
};