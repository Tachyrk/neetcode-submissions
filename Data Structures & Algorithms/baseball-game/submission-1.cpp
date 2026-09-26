class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<long long> st;
        for(auto &s : operations){
            if(s == "+"){
                long long score1 = st.top();
                st.pop();
                long long score2 = st.top();
                st.push(score1);
                st.push(score1 + score2);
            }else if(s == "D"){
                long long score = st.top();
                st.push(2 * score);
            }else if(s == "C"){
                st.pop();              
            }else{
                st.push(stoi(s));
            }           
        }

        long long ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};