class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int limit = 0, farest = nums[0], step = 0;        
        for(int i = 0; i < n; i++){
            if(i > limit){
                limit = farest;
                step++;
            }
            farest = max(farest, nums[i] + i);
        }
        return step;
    }
};
