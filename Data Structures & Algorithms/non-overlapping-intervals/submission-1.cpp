class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        if(n == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        int currEnd = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < currEnd){
                ans++;
                // 【關鍵修改】：保留結束時間比較早的那一個，因為它留給後面的空間比較大
                currEnd = min(currEnd, intervals[i][1]);
            }else{
                currEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
