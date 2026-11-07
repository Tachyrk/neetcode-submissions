class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {      
        /*int n = equations.size();
        vector<int> parent(41); // 20 * 2 + 1
        iota(parent.begin(), parent.end(), 0);
        
        auto find = [&](auto &self, int x)->int{           
            if(parent[x] != x){
                parent[x] = self(self, parent[x]);
            }
            return parent[x];
        };

        auto unite = [&](int x, int y)->void{
            int root_x = find(find, x);
            int root_y = find(find, y);
            if(root_x != root_y){
                parent[root_x] = root_y;
            }
        };

        unordered_map<int, vector<pair<int, double>>> neighbor;
        unordered_map<string, int> map;
        int idx = 0;
        for(int i = 0; i < n; i++){
            string Ai = equations[i][0];            
            if(map.find(Ai) == map.end()){
                map[Ai] = idx++;
            }
            int A_idx = map[Ai];
            string Bi = equations[i][1];
            if(map.find(Bi) == map.end()){
                map[Bi] = idx++;
            }
            int B_idx = map[Bi];
            double val = values[i];
            neighbor[A_idx].push_back({B_idx, val});
            neighbor[B_idx].push_back({A_idx, (double)1.0 / val});
            unite(A_idx, B_idx);
        }

        auto cal_res = [&](int C_idx, int D_idx)->double{
            if(C_idx == D_idx){
                return (double) 1.0;               
            }

            int root_c = find(find, C_idx);
            int root_d = find(find, D_idx);
            if(root_c != root_d){
                return (double) -1.0;        
            }

            queue<pair<int, double>> q;
            vector<bool> visited(idx, false);
            visited[C_idx] = true;
            q.push({C_idx, 1.0});
            while(!q.empty()){
                auto [current, res] = q.front();
                q.pop();
                if(current == D_idx){
                    return res;                   
                }
                for(auto &[next_idx, w] : neighbor[current]){
                    if(!visited[next_idx]){
                        if(next_idx == D_idx){
                            return res * w;                            
                        }
                        visited[next_idx] = true;
                        q.push({next_idx, res * w});
                    }
                }
            }

            return (double) -1.0;
        };

        int m = queries.size();
        vector<double> ans(m, 0.0);

        for(int j = 0; j < m; j++){     
            string Cj = queries[j][0];
            if(map.find(Cj) == map.end()){
                ans[j] = -1.0;
                continue;
            }
            int C_idx = map[Cj];

            string Dj = queries[j][1];
            if(map.find(Dj) == map.end()){
                ans[j] = -1.0;
                continue;
            }
            int D_idx = map[Dj];

            ans[j] = cal_res(C_idx, D_idx);            
        }

        return ans;*/

        int n = equations.size();
        int max_vars = n * 2;

        unordered_map<string, int> str_to_id;
        auto get_id = [&](const string& s) {
            auto it = str_to_id.find(s);
            if (it != str_to_id.end()) return it->second;
            int new_id = str_to_id.size();
            return str_to_id[s] = new_id;
        };

        // 連續記憶體結構：效能與 Cache Locality 最佳
        vector<int> parent(max_vars);
        iota(parent.begin(), parent.end(), 0);
        vector<double> weight(max_vars, 1.0); // weight[x] = x / parent[x]

        // 帶權並查集：路徑壓縮 + 權重累乘
        auto find = [&](auto& self, int x) -> int {
            if (parent[x] != x) {
                int origin_parent = parent[x];
                parent[x] = self(self, parent[x]);
                weight[x] *= weight[origin_parent];
            }
            return parent[x];
        };

        // 集合合併：動態計算 root_a -> root_b 的倍率
        auto unite = [&](int a, int b, double val) {
            int root_a = find(find, a);
            int root_b = find(find, b);
            if (root_a != root_b) {
                parent[root_a] = root_b;
                weight[root_a] = (val * weight[b]) / weight[a];
            }
        };

        // 1. 建構並查集
        for (int i = 0; i < n; i++) {
            int u = get_id(equations[i][0]);
            int v = get_id(equations[i][1]);
            unite(u, v, values[i]);
        }

        // 2. 處理查詢（O(1) 回答）
        int m = queries.size();
        vector<double> ans(m, -1.0);

        for (int j = 0; j < m; j++) {
            auto it_c = str_to_id.find(queries[j][0]);
            auto it_d = str_to_id.find(queries[j][1]);

            // 未曾出現的變數直接回傳 -1.0
            if (it_c == str_to_id.end() || it_d == str_to_id.end()) {
                continue;
            }

            int c = it_c->second;
            int d = it_d->second;

            int root_c = find(find, c);
            int root_d = find(find, d);

            if (root_c == root_d) {
                // c / d = (c / root) / (d / root)
                ans[j] = weight[c] / weight[d];
            }
        }

        return ans;
    }
};