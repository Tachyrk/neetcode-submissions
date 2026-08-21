class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        // 在尾端補 0，確保最後迴圈結束前，棧內所有剩餘的柱子都會被強制彈出並結算面積
        heights.push_back(0); 
        
        vector<int> st; // 單調遞增棧，用來儲存柱子的「索引 (index)」
        
        for(int i = 0; i < heights.size(); i++) {
            // 當前柱子比棧頂柱子矮時，代表找到了棧頂柱子的「右邊界」
            while(!st.empty() && heights[i] < heights[st.back()]) {
                int h = heights[st.back()]; // 取出要計算矩形的「高度」
                st.pop_back();              // 彈出棧頂
                
                // 計算「寬度」
                // 右邊界是當前的 i
                // 左邊界是彈出後，新的棧頂索引 st.back() (因為是單調遞增，它一定比剛彈出的矮)
                // 如果棧空了，代表剛彈出的柱子左邊沒有比它更矮的，寬度可以直接延伸到最左邊 (即 i)
                int w = st.empty() ? i : (i - st.back() - 1);
                
                ans = max(ans, h * w); // 更新最大面積
            }
            // 將當前索引推入棧中，保持棧的高度遞增特性
            st.push_back(i);
        }
        
        return ans;
    }
};