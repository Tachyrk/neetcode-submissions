class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {        
        int n = intervals.size();
        vector<vector<int>> ans;
        
        int index = 0;
        while(index < n && intervals[index][1] < newInterval[0]){
            ans.push_back(intervals[index]);
            index++;
        }
        
        if(index < n && intervals[index][0] <= newInterval[1]){
            int start = min(intervals[index][0], newInterval[0]);
            int end = max(intervals[index][1], newInterval[1]);
            while(index < n && intervals[index][0] <= end){
                end = max(intervals[index][1], newInterval[1]);
                index++;
            }
            ans.push_back({start, end});
        }else{
            ans.push_back(newInterval);
        }

        while(index < n){
            ans.push_back(intervals[index]);
            index++;
        }
        

        return ans;
    }
};
