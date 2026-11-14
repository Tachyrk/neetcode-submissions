class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> room_use_cnt(n, 0);
        int max_cnt = 0;

        set<int> valid_room;
        for(int i = 0; i < n; i++) valid_room.insert(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> waiting_pq;
        long long current_time = 0;

        for(vector<int> &meeting : meetings){
            long long start_time = meeting[0];
            long long end_time = meeting[1];

            current_time = max(current_time, start_time);
            if(valid_room.empty() && current_time < waiting_pq.top().first){
                current_time = waiting_pq.top().first;
            }

            while(!waiting_pq.empty() && current_time >= waiting_pq.top().first){
                int room_idx = waiting_pq.top().second;
                waiting_pq.pop();
                valid_room.insert(room_idx);
            }

            auto it = valid_room.begin();
            int room_idx = *it;
            valid_room.erase(room_idx);
            room_use_cnt[room_idx]++;
            max_cnt = max(max_cnt, room_use_cnt[room_idx]);
            waiting_pq.push({current_time + (end_time - start_time), room_idx});
        }

       
        for(int i = 0; i < n; i++){
            if(room_use_cnt[i] == max_cnt) return i;           
        }

        return 0;
    }
};