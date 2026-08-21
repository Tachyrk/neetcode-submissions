class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        int n = nums.size();
        vector<pair<int, int>> sorted_array(n);      
        for(int i = 0; i < n; i++){
            sorted_array[i] = {nums[i], i}; 
        }

        sort(sorted_array.begin(), sorted_array.end());
        int left = 0, right = n - 1;
        while(left < right){
            int sum = sorted_array[left].first + sorted_array[right].first;
            if(sum == target){                
                int index1 = sorted_array[left].second;
                int index2 = sorted_array[right].second;
                return {min(index1, index2), max(index1, index2)};
            } 
            if(sum > target) right--;
            else left++;
        }
        return {-1,-1};
    }
};
