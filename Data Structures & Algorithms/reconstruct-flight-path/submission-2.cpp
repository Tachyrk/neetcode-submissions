class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> neighbors;       
        for(auto &ticket : tickets){
            string u = ticket[0];
            string v = ticket[1];
            neighbors[u].push(v);            
        }

        vector<string> ans;
        stack<string> st;
        st.push("JFK");        
        while(!st.empty()){
            string current = st.top();          
            if(!neighbors[current].empty()){
                st.push(neighbors[current].top());
                neighbors[current].pop();
            }else{
                ans.push_back(current);
                st.pop();
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
