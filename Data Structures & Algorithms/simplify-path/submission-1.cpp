class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        int i = 0;
        
        vector<string> st(n);
       
        int idx = 0;
        while(i < n){
            while(i < n && path[i] == '/') i++;
            if(i == n) break;

            int nextidx = path.find('/', i);
            if(nextidx == string::npos) nextidx = n;
            string token = path.substr(i, nextidx - i);

            if(token == ".."){
                if(idx > 0) idx--;
            }
            else if(token != "."){
                st[idx++] = token;
            }
            i = nextidx;
        }

        string ans = "";
        ans.reserve(n);
        for(int i = 0; i < idx; i++){
            ans += "/";
            ans += st[i];
        }

        return ans == "" ? "/" : ans;
    }
};