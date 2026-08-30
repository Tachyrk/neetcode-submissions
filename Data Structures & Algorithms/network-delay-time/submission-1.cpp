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

        vector<int> timespend(n + 1, INT_MAX);
        timespend[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto [current_time , current_node] = pq.top();
            pq.pop();
            for(const auto& neighbor : neighbors[current_node]){
                int next = neighbor.first;
                int cost = neighbor.second;                
                if(timespend[current_node] + cost < timespend[next]){
                    timespend[next] = timespend[current_node] + cost;
                    pq.push({timespend[next], next});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(timespend[i] == INT_MAX) return -1;
            ans = max(ans, timespend[i]);
        }

        return ans;
    }
};
