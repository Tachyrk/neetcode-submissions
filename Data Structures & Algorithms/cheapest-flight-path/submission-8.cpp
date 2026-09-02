class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {       
        // 這題陰的很，有額外限制的最好限制也要記錄避免死掉的 path 影響狀態。
        vector<vector<pair<int, int>>> neighbors(n);
        for(auto & flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            neighbors[u].push_back({v, price});
        }

        vector<vector<int>> total_cost(n, vector<int>(k + 2, INT_MAX));
        total_cost[src][k + 1] = 0;
        //<total_cost, <k, src>>
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {k + 1, src}}); //k + 1 for src
        while(!pq.empty()){
            auto [curr_cost, info] = pq.top();
            auto [curr_k, curr_node] = info;
            if (curr_node == dst) return curr_cost; // 提早結束，第一名到達的絕對是最便宜的
            pq.pop();
            if(!curr_k) continue;
            for(auto &[next, cost] : neighbors[curr_node]){
                //if(next == dst) return (cost + curr_cost);
                if(cost + curr_cost < total_cost[next][curr_k - 1]){
                    total_cost[next][curr_k - 1] = cost + curr_cost;
                    pq.push({total_cost[next][curr_k - 1], {curr_k - 1, next}});
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < k + 2; i++){
            ans = min(ans, total_cost[dst][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
