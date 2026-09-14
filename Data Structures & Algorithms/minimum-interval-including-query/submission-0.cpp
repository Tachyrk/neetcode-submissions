class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();

        vector<pair<int, int>> sorted_arr(m);
        for(int i = 0; i < m; i++){
            sorted_arr[i] = {queries[i], i};
        }
        sort(sorted_arr.begin(), sorted_arr.end());
        sort(intervals.begin(), intervals.end());

        vector<int>ans(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int idx = 0;
        for(int i = 0; i < m; i++){
            int q_start = sorted_arr[i].first;
            int origin_idx = sorted_arr[i].second;
            while(idx < n && intervals[idx][0] <= q_start){
                pq.push({intervals[idx][1] - intervals[idx][0] + 1, intervals[idx][1]});
                idx++;
            }
            while(!pq.empty() && pq.top().second < q_start){
                pq.pop();
            }

            if(!pq.empty()){
                ans[origin_idx] = pq.top().first;
            }else{
                ans[origin_idx] = -1;
            }
        }

        return ans;
    }
};
