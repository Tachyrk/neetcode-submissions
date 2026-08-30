class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neighbors(n + 1);
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int cost = time[2];
            neighbors[u].push_back({v, cost});
        }

        int invalid_node = n - 1;        
        vector<int> timespend(n + 1, INT_MAX);
        timespend[k] = 0;
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(auto neighbor : neighbors[current]){
                int next = neighbor.first;
                int cost = neighbor.second;
                if(timespend[next] == INT_MAX) invalid_node--;
                if(timespend[current] + cost < timespend[next]){
                    timespend[next] = timespend[current] + cost;
                    q.push(next);
                }
            }
        }

        if(invalid_node != 0) return -1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, timespend[i]);
        }

        return ans;
    }
};
