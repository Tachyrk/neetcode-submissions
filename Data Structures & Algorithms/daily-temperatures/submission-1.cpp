class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> st(n);        
        vector<int> ans(n, 0);

        int index = 0;       
        for(int i = 0; i < n; i++){            
            while(index > 0 && temperatures[st[index - 1]] < temperatures[i]){
                ans[st[index - 1]] = i - st[index - 1];
                index--;
            }
            st[index++] = i;
        }
       
        return ans;
    }
};
