class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        int remain_Courses = numCourses;
        vector<vector<int>> neighbors(numCourses);
        for(auto prerequisit : prerequisites){
            int u = prerequisit[1];
            int v = prerequisit[0];
            neighbors[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> ans;
        vector<int> invalid;
        ans.reserve(numCourses);
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
                remain_Courses--;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbor : neighbors[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                    ans.push_back(neighbor);
                    remain_Courses--;
                }
            }
        }

        return remain_Courses == 0 ? ans : invalid;
    }
};
