class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> neighbors(n);      
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            neighbors[u].push_back(v);
            neighbors[v].push_back(u);           
        }

        vector<int> degree(n, 0);     
        queue<int> q;       
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(neighbors[i].size() == 1){
                q.push(i);                
                ans.push_back(i);
            }
            degree[i] = neighbors[i].size();
        }
        
        while(!q.empty()){
            int cnt = q.size();
            vector<int> temp;
            while(cnt--){
                int node = q.front();
                q.pop();
                for(int neighbor : neighbors[node]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1){
                        q.push(neighbor);
                        temp.push_back(neighbor);                        
                    }
                }
            }
            if(temp.size() > 0) ans = move(temp);
        }

        return ans;
    }
};