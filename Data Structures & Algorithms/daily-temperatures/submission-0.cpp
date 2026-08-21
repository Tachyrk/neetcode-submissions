class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<pair<int, int>> st(n);        
        vector<int> ans(n);

        int index = 0;       
        for(int i = 0; i < n; i++){
            int count = 1;
            while(index > 0 && st[index - 1].first < temperatures[i]){
                ans[st[index - 1].second] = i - st[index - 1].second;
                index--;
            }
            st[index++] = {temperatures[i], i};
        }

        while(index > 0){
            ans[st[index - 1].second] = 0;
            index--;
        }
        return ans;
    }
};
