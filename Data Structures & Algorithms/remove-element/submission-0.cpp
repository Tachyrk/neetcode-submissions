class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == val){
                continue;
            }else{
                swap(nums[idx], nums[i]);
                idx++;
            }
        }
        
        return idx;
    }
};