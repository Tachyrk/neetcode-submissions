class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        if(n == 1) return words[0];
        unordered_map<char, unordered_set<char>> neighbors;
        vector<int> indegree(26, -1);

        for(int i = 1; i < n; i++){
            string &s1 = words[i - 1];
            string &s2 = words[i];
            int l1 = s1.size();
            int l2 = s2.size();
            int index1 = 0, index2 = 0;
            while(index1 < l1 && index2 < l2 && s1[index1] == s2[index2]){
                index1++;
                index2++;
            }
            for(char c : s1){
                int idx = c - 'a';
                if(indegree[idx] == -1) indegree[idx] = 0;
            }
            for(char c : s2){
                int idx = c - 'a';
                if(indegree[idx] == -1) indegree[idx] = 0;
            }
            if(l1 == index1 && l2 == index2) continue;
            if(l2 == index2) return "";
            if(l1 == index1) continue;
            if(neighbors[s1[index1]].find(s2[index2]) == neighbors[s1[index1]].end()){
                neighbors[s1[index1]].insert(s2[index2]);
                //if(indegree[s1[index1] - 'a'] == -1) indegree[s1[index1] - 'a'] = 0;
                //if(indegree[s2[index2] - 'a'] == -1) indegree[s2[index2] - 'a'] = 0;
                indegree[s2[index2] - 'a']++;
            }            
        }
        string ans;
        queue<char> q;
        int remain_cnt = 0;
        for(int i = 0; i < 26; i++){
            if(indegree[i] == 0){
                q.push(i + 'a');
            }else if(indegree[i] > 0){
                remain_cnt++;
            }
        }

        while(!q.empty()){
            char current = q.front();
            q.pop();
            ans.push_back(current);
            for(auto neighbor : neighbors[current]){
                int idx = neighbor - 'a';
                indegree[idx]--;
                if(indegree[idx] == 0){
                    remain_cnt--;
                    q.push(neighbor);
                }
            }
        }

        return (remain_cnt > 0) ? "" : ans;
    }
};
