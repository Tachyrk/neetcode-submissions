class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> room_use_cnt(n, 0);

        priority_queue<int, vector<int>, greater<int>> valid_room;
        for (int i = 0; i < n; i++) valid_room.push(i);

        // {結束時間, 房號}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> waiting_pq;

        for (const auto& meeting : meetings) {
            long long start_time = meeting[0];
            long long duration = meeting[1] - meeting[0];

            // 1. 先釋放所有在 start_time 之前（含當下）已結束的會議室
            while (!waiting_pq.empty() && waiting_pq.top().first <= start_time) {
                valid_room.push(waiting_pq.top().second);
                waiting_pq.pop();
            }

            // 2. 有空房就直接用，沒空房就等最早結束的那間並順延時間
            if (!valid_room.empty()) {
                int room_idx = valid_room.top();
                valid_room.pop();
                room_use_cnt[room_idx]++;
                waiting_pq.push({start_time + duration, room_idx});
            } else {
                auto [free_time, room_idx] = waiting_pq.top();
                waiting_pq.pop();
                room_use_cnt[room_idx]++;
                waiting_pq.push({free_time + duration, room_idx});
            }
        }

        return max_element(room_use_cnt.begin(), room_use_cnt.end()) - room_use_cnt.begin();
    }
};