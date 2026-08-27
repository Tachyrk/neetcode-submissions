class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_idx(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            last_idx[idx] = i;
        }

        vector<int> ans;
        int last = -1;
        int begin = 0;
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            last = max(last_idx[idx], last);
            if(last == i){
                ans.push_back(last - begin + 1);
                begin = i + 1;
            }            
        }

        return ans;
    }
};
