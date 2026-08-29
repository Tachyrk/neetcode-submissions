class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }

        auto find = [&](auto &self, int x)->int{
            if(x != parent[x]){
                parent[x] = self(self, parent[x]);
            }
            return parent[x];
        };

        auto connect = [&](int x, int y)->bool{
            int rootx = find(find, x);
            int rooty = find(find, y);
            if(rootx == rooty) return false;
            parent[rootx] = rooty;
            return true;
        };
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(connect(u, v) == false){
                return edge;
            };
        }
        return edges[0];
    }
};
