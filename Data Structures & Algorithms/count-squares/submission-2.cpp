class CountSquares {
public:
    CountSquares() {
        
    }
    unordered_map<int, vector<int>> y_map;
    unordered_map<int, int> point_map;

    int encode(int x, int y){
        return x * 1001 + y;
    }
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int idx = encode(x, y);
        y_map[y].push_back(x);
        point_map[idx]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int cnt;
        int ans = 0;
        for(int p1x : y_map[y]){ //another point at same y with point.
            if(p1x == x) continue;
            int d = abs(p1x - x);
            //check points above the point.            
            //int p1idx = encode(p1x, y);
            int p2idx = encode(p1x, y + d);
            int p3idx = encode(x, y + d);
            cnt = 1;
            if(point_map.find(p2idx) == point_map.end()) cnt = 0;
            if(point_map.find(p3idx) == point_map.end()) cnt = 0;
            if(cnt != 0) ans += (cnt * point_map[p2idx] * point_map[p3idx]);

            //check points below the point.
            cnt = 1;
            p2idx = encode(p1x, y - d);
            p3idx = encode(x, y - d);
            if(point_map.find(p2idx) == point_map.end()) cnt = 0;
            if(point_map.find(p3idx) == point_map.end()) cnt = 0;
            if(cnt != 0) ans += (cnt * point_map[p2idx] * point_map[p3idx]);
        }

        return ans;
    }
};
