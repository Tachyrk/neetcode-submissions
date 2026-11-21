class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>idle_projects;
        priority_queue<int> avaliable_project;
        int n = profits.size();
        for(int i = 0; i < n; i++){
            idle_projects.push({capital[i], profits[i]});
        }

        long long gain = w;
        for(int i = 0; i < k; i++){
            while(!idle_projects.empty() && idle_projects.top().first <= gain){
                avaliable_project.push(idle_projects.top().second);
                idle_projects.pop();
            }

            if(avaliable_project.empty()) break;

            gain += avaliable_project.top();
            avaliable_project.pop();
        }

        return gain;
    }
};