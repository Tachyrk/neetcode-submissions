class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        
        while(q.size() >= 2){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if(x != y){
                q.push(abs(x - y));
            }
        }

        return q.empty() ? 0 : q.top();
    }
};
