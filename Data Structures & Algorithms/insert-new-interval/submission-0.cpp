class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
        });
        
        int n = intervals.size();
        vector<vector<int>> ans;
        int current_start = intervals[0][0];
        int current_end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] > current_end){
                ans.push_back({current_start, current_end});
                current_start = intervals[i][0];
                current_end = intervals[i][1];
            }else{
                current_end = max(current_end, intervals[i][1]);
            }
        }
        ans.push_back({current_start, current_end});

        return ans;
    }
};
