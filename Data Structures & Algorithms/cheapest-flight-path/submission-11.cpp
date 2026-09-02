class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {       
        vector<vector<pair<int, int>>> neighbors(n);
        for(auto & flight : flights){
            neighbors[flight[0]].push_back({flight[1], flight[2]});
        }

        // 記錄抵達該節點時，曾擁有的「最大剩餘中轉次數」
        vector<int> k_remain(n, -1);
        
        using Node = pair<int, pair<int, int>>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, {k + 1, src}}); 

        while(!pq.empty()){
            auto [curr_cost, info] = pq.top();
            auto [curr_k, curr_node] = info;
            pq.pop(); 
            
            // 【關鍵修正】在 Pop 時才檢查！
            // 如果我們曾用「更便宜的價格 (因為先被 pop)」且「剩餘次數更多或一樣」抵達過這裡，這條路徑就沒用了
            if (curr_k <= k_remain[curr_node]) continue;
            
            // 更新該節點目前的最大剩餘次數
            k_remain[curr_node] = curr_k;
            
            if (curr_node == dst) return curr_cost; 
            
            if(!curr_k) continue;
            
            for(auto &[next, cost] : neighbors[curr_node]){
                // 無條件推進去，讓 PQ 幫我們按照花費排序，等 Pop 出來時再做過濾
                pq.push({cost + curr_cost, {curr_k - 1, next}});
            }
        }
        
        return -1; 
    }
};