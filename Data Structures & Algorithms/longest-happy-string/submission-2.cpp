class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n = a + b + c;
        priority_queue<pair<int, int>> pq;
        string ans;
        ans.reserve(n);

        if(a) pq.push({a, 0});
        if(b) pq.push({b, 1});
        if(c) pq.push({c, 2});

        queue<pair<int, int>> waitq;
        int prev = -1;
        while(!pq.empty()){            
            auto [cnt, letter] = pq.top();
            pq.pop();
            if(!waitq.empty()){
                pq.push(waitq.front());
                waitq.pop();
            }

            ans.push_back(letter + 'a');
            cnt--;
            if(prev == letter && cnt > 0){
                waitq.push({cnt, letter});
            }else if(cnt > 0){
                pq.push({cnt, letter});
            }
            prev = letter;
        }
        //return ans.size() == n ? ans : "";  
        return ans;      
    }
};