class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int remain_course = numCourses;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> neibor(numCourses);
        for(auto rerequisit : prerequisites){
            int u = rerequisit[1];
            int v = rerequisit[0];
            neibor[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                remain_course--;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto next : neibor[node]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                    remain_course--;
                }
            }
        }

        return remain_course == 0;
    }
};
