/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1) return n;

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 1;
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top() <= intervals[i].start){
                pq.pop();
            }
            pq.push(intervals[i].end);
            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};
