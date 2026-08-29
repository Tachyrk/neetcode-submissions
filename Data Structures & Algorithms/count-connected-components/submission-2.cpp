class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        auto find = [&](auto &self, int x)->int{
            if(x != parent[x]){
                parent[x] = self(self, parent[x]);
            }
            return parent[x];
        };

        
        auto connect = [&](int x, int y)-> bool{
            int rootx = find(find, x);
            int rooty = find(find, y);           
            if (rootx == rooty) return false; // 已經是同家族，合併失敗
            parent[rootx] = rooty;           
            return true; // 成功合併兩個不同家族
        };

        int ans = n; // 一開始預設有 n 個獨立家族
        for(auto& edge : edges){
            if (connect(edge[0], edge[1])) {
                ans--; // 只要成功合併一次，總家族數就少 1
            }
        }

        /*unordered_set<int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int root = find(find, i);
            if(mp.find(root) == mp.end()){
                ans++;
                mp.insert(root);
            }
        }*/

        return ans;    
    }
};
