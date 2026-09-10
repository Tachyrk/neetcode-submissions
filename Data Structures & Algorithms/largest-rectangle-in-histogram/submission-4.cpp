class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ans = 0;
        int n = heights.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : (i - 1) - st.top();
                ans = max(ans, h * w);
            }
            st.push(i);
        }

        return ans;
    }
};
