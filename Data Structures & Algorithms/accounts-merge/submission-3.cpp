class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int idx = 0;
        unordered_map<string, pair<int, string>> mp;
        unordered_map<int, string> idxToEmail;
        for(auto account : accounts){
            int n = account.size();
            for(int i = 1; i < n; i++){
                if(mp.find(account[i]) == mp.end()){
                    mp[account[i]] = {idx++, account[0]};
                    idxToEmail[idx - 1] = account[i];
                }
            }
        }

        vector<int> parent(idx, 0);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&](auto &self, int a)->int{
            if(parent[a] != a){
                parent[a] = self(self, parent[a]);
            }
            return parent[a];
        };
        auto unite = [&](int a, int b)->void{
            int roota = find(find, a);
            int rootb = find(find, b);
            if(roota != rootb){
                parent[rootb] = roota;         
            }
            return;
        };

        for(auto account : accounts){
            int n = account.size();
            for(int i = 2; i < n; i++){
                unite(mp[account[i]].first, mp[account[i - 1]].first);
            }
        }
        unordered_map<int, vector<string>> group_emails;
        for(int i = 0; i < idx; i++){
            int root = find(find, i);
            if(group_emails.find(root) == group_emails.end()){
                group_emails[root] = {};
            }
            group_emails[root].push_back(idxToEmail[i]);
        }

        vector<vector<string>> ans;
        ans.reserve(group_emails.size());
        for(auto &[root, email] : group_emails){
            sort(email.begin(), email.end());
            vector<string> temp;
            temp.reserve(email.size() + 1);
            temp.push_back(mp[email[0]].second); //push user name
            temp.insert(temp.end(), email.begin(), email.end()); 
            ans.push_back(move(temp));
        }
        return ans;
    }
};