class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto stone : stones){
            q.push(stone);            
        }
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
