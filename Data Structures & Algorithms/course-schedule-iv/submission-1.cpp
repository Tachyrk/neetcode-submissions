class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {        
        vector<vector<bool>> is_prerequest(numCourses, vector<bool>(numCourses, false));

        for(auto &prerequisit : prerequisites){
            int u = prerequisit[0];
            int v = prerequisit[1];
            is_prerequest[u][v] = true;
        } 

        
        for(int k = 0; k < numCourses; k++){
            for(int i = 0; i < numCourses; i++){
                for(int j = 0; j < numCourses; j++){
                    if (is_prerequest[i][k] && is_prerequest[k][j]) {
                        is_prerequest[i][j] = true;
                    }                   
                }
            }
        }


        int n = queries.size();
        vector<bool> ans;
        ans.reserve(n);

        for(auto & query: queries){
            int u = query[0];
            int v = query[1];
            ans.push_back(is_prerequest[u][v]);            
        }

        return ans;
    }
};