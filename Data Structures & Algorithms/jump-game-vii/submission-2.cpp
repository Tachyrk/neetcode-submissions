class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n - 1] == '1') return false;

        /*int farest = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            if(node == n - 1) return true;
            q.pop();
            int min_can_reach = max(farest + 1, node + minJump);
            int max_can_reach = min(n - 1, node + maxJump);
            for(int i = min_can_reach; i <= max_can_reach; i++){
                if(i == n - 1) return true;
                if(s[i] == '0') q.push(i);
            }
            farest = max(farest, node + maxJump);
        }
        return false;*/

        vector<bool> dp(n, false);
        dp[0] = true;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(i >= minJump && dp[i - minJump] == true) cnt++;
            if(i > maxJump && dp[i - maxJump - 1] == true) cnt--;
            if(s[i] == '0' && cnt) dp[i] = true;
        }
        return dp[n - 1];
    }
};