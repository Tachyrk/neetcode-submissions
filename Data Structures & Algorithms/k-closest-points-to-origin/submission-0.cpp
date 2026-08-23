class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 使用預設的 Max-Heap，裡面裝 pair<距離平方, 點的座標>
        priority_queue<pair<long long, vector<int>>> pq;
        
        for (const auto& point : points) {
            long long x = point[0];
            long long y = point[1];
            long long dist = x * x + y * y;
            
            pq.push({dist, point});
            
            // 如果數量超過 k，把距離最遠的 (最大值) 踢掉
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        // 把剩下的 k 個最小元素倒進 ans
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};