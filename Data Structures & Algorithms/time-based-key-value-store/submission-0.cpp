class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) != mp.end()){
            const auto &vec = mp[key];
            int n = vec.size();
            int left = 0, right = n - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                int time = vec[mid].first;
                if(time <= timestamp){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

            if(right < 0) return "";
            return vec[right].second;
        }else{
            return "";
        }
    }
};
