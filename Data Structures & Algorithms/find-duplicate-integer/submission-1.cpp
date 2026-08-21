class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        
        // 第一階段：快慢指標出發，找到在環內的相遇點
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) {                
                break;
            }
        }
        
        // 第二階段：一個指標回到起點，兩者同速前進，相遇點即為環的入口
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        // slow 本身就是環的入口，也就是那個重複的數字
        return slow; 
    }
};