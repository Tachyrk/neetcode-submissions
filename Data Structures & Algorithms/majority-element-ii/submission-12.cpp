class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elementA = INT_MIN, countA = 0;
        int elementB = INT_MIN, countB = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] == elementA){
                countA++;
            }else if(nums[i] == elementB){
                countB++;
            }else if(countA == 0){
                elementA = nums[i];
                countA = 1;
            }   
            else if(countB == 0){
                elementB = nums[i];
                countB = 1;
            }else{
                countA--;
                countB--;
            }                 
        }

        vector<int> ans;
        ans.reserve(2);
        countA = 0, countB = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == elementA){
                countA++;
            }else if(nums[i] == elementB){
                countB++;
            }
        }

        if(countA > n / 3) ans.push_back(elementA);
        if(countB > n / 3) ans.push_back(elementB);

        return ans;
    }
};