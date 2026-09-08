class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        while(left < right){
            if(height[left] < height[right]){
                int i = left + 1;
                while(i <= right && height[i] < height[left]){
                    ans += (height[left] - height[i]);
                    i++;
                }
                left = i;
            }else{
                int i = right - 1;
                while(i >= left && height[i] < height[right]){
                    ans += (height[right] - height[i]);
                    i--;
                }
                right = i;
            }
        }

        return ans;
    }
};
