class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int num : nums){
            q.push(num);
            if(q.size() > k) q.pop();
        }
        return q.top();
    }
};
