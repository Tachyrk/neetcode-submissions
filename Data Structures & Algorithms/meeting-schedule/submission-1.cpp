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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return (a.start == b.start) ? (a.end > b.end) : (a.start < b.start);
        });
        for(int i = 1; i < n; i++){
            if(intervals[i].start < intervals[i - 1].end) return false;
        }

        return true;
    }
};
