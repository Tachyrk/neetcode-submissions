class Solution {
public:
    struct STAT{
        int maxdiff;
        int x;
        int y;        
        bool operator()(const auto &a, const auto&b){
            return a.maxdiff > b.maxdiff;
        };
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        priority_queue<STAT, vector<STAT>, STAT> pq;
        pq.push(STAT(0, 0, 0));
        int x_dir[4] = {1, 0, -1, 0};
        int y_dir[4] = {0, 1, 0, -1};
        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();
            if(current.x == m - 1 && current.y == n - 1){
                return current.maxdiff;
            }
            for(int nd = 0; nd < 4; nd++){
                int newx = current.x + x_dir[nd];
                int newy = current.y + y_dir[nd];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n){
                    int diff = max(current.maxdiff, abs(heights[newx][newy] - heights[current.x][current.y]));
                    if(dp[newx][newy] > diff){
                        dp[newx][newy] = diff;
                        pq.push(STAT(diff, newx, newy));
                    }
                }
            }
        }
        return 0;
    }
};