class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1;
        while(l <= r){
            if(nums[l] == nums[l - 1]){
                for(int i = r; i > l; i--){
                    swap(nums[i], nums[l]);
                }
                r--;
            }else{
                l++;
            }            
        }

        nums.resize(r + 1);
        return r + 1;
    }
};