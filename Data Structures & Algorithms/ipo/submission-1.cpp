class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {        
        /*priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>idle_projects;
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

        return gain;*/

        int n = profits.size();
        if (n == 0 || k == 0) return w;

        // 1. 全解鎖快速通道：初始資金已大於等於所有專案門檻
        int max_cap = *max_element(capital.begin(), capital.end());
        if (w >= max_cap) {
            int take = min(k, n);
            // 直接利用 non-const reference 原地做 Introselect，平均 O(N) 切出前 take 大
            nth_element(profits.begin(), profits.begin() + take, profits.end(), greater<int>());
            return accumulate(profits.begin(), profits.begin() + take, static_cast<long long>(w));
        }

        // 2. 連續記憶體排序 + 單向指標取代 Min-Heap
        vector<pair<int, int>> projects;
        projects.reserve(n);
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> available;
        long long gain = w;
        int idx = 0;

        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= gain) {
                available.push(projects[idx].second);
                ++idx;
            }
            if (available.empty()) break;

            gain += available.top();
            available.pop();
        }

        return gain;
    }
};