class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 建議有空跟 Gemini 多了解一下線段數的複雜玩法， 但準備面試寫得出來暴力解就行
        int n = points.size();
        vector<int> MIN_DIST(n, INT_MAX);
        vector<bool> visited(n, false);

        auto calculate_dis = [&](const int a, const int b)->int{
            return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
        };
        MIN_DIST[0] = 0;

        int ans = 0;
        for(int i = 0; i < n; i++){            
            int min_dis = INT_MAX;
            int idx = -1;
            for(int j = 0; j < n; j++){                
                if(visited[j] == false){                  
                    if(MIN_DIST[j] < min_dis){
                        min_dis = MIN_DIST[j];
                        idx = j;
                    }
                }
            }

            visited[idx] = true;
            ans += min_dis;

            for(int j = 0; j < n; j++){                
                if(visited[j] == false){
                    int dis = calculate_dis(idx, j);
                    MIN_DIST[j] = min(MIN_DIST[j], dis);
                }
            }
        }
        
        return ans;
    }
};
