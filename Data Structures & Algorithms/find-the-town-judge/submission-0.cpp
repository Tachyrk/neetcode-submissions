class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted_count(n + 1, 0);
        for(auto &element : trust){
            int u = element[0];
            int v = element[1];
            trusted_count[u]--;
            trusted_count[v]++;
        }

        for(int i = 1; i <= n; i++){
            if(trusted_count[i] == n - 1) return i;
        }

        return -1;
    }
};