class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {      
        int n = equations.size();
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

        return ans;
    }
};