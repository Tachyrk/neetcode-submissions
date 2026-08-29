class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 標準 Union find 模板  建議重寫保持感覺
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        auto find = [&](auto &self, int x)-> int{           
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

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int rootu = find(find, u);
            int rootv = find(find, v);
            if(!connect(u, v)) return false;            
        }

        int prevroot = find(find, 0);
        for(int i = 1; i < n; i++){
            int root = find(find, i);
            if(root != prevroot) return false;
        }
        return true;
    }
};
