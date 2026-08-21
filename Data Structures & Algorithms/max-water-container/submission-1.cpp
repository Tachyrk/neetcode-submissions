class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        int left = 0, right = n - 1;
        while(left < right){
            ans = max(ans, min(heights[left], heights[right]) * (right - left));
            if(heights[left] >= heights[right]) right--;
            else left++;
        }

        return ans;
    }
};
