class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int n = nums.size();
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(cnt == 0){
                major = nums[i];
                cnt = 1;
            }else{
                if(nums[i] == major) cnt++;
                else{
                    cnt--;                    
                }
            }            
        }
        return major;
    }
};