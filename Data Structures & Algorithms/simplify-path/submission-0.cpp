class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int i = 0, n = path.size();
        int next_idx = 0;   
        while(i < n){                    
            if(path[i] == '/'){
                if(st.empty()){
                    st.push_back("/");
                }else if(st.back() != "/"){
                    st.push_back("/");
                }                
                next_idx = i + 1;
            }else{                
                next_idx = path.find('/', i);               
                if(next_idx == string::npos){
                    next_idx = n;
                }
                string word = path.substr(i, next_idx - i);    
                if(word == "."){
                    // current dictory, skip, do nothing.
                }else if(word == ".."){
                    if(!st.empty()) st.pop_back();
                    if(!st.empty()) st.pop_back();                  
                    // parent dictory
                }else{
                    st.push_back(word);
                }
            }
            i = next_idx;
        }

        string ans = "/";
        ans.reserve(n);
        st.pop_front();
        while(!st.empty() && st.back() == "/") st.pop_back();
        while(!st.empty()){
            ans += st.front();
            st.pop_front();
        }

        return ans;
    }
};