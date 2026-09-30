class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        ans.reserve(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitpq;
        for(int i = 0; i < n; i++){
            waitpq.push({tasks[i][0], i});
        }
        int starttime = 0;
        while(!pq.empty() || !waitpq.empty()){
            if(!pq.empty()){
                auto task = pq.top();
                pq.pop();
                ans.push_back(task.second);
                starttime += task.first;
            }else{
                starttime = waitpq.top().first;
            }

            while(!waitpq.empty() && waitpq.top().first <= starttime){
                auto task = waitpq.top();
                int idx = task.second;
                waitpq.pop();
                pq.push({tasks[idx][1], idx});
            }
        }

        return ans;
    }
};