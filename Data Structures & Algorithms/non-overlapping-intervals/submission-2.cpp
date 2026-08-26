class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        if(n == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a[1] < b[1]; // 誰的結束時間早，誰就排前面
        });

        int currEnd = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < currEnd){
                ans++;                
            }else{
                currEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
