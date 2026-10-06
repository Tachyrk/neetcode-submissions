class Solution {
public:
       string reorganizeString(string s) {
        int freq[26] = {0};
        for(char c : s) freq[c - 'a']++;

        priority_queue<pair<int, int>> pq;   
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitq;                
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){                
                pq.push({freq[i], i});               
            }
        }

        string ans;
        ans.reserve(s.size());
        int current_idx = 0;
        while(!pq.empty() || !waitq.empty()){
            if(pq.empty()) return "";           
            auto [remain_count, idx] = pq.top();
            pq.pop();            
            ans.push_back(idx + 'a');
            freq[idx]--;
            if(freq[idx] >= 1){
                waitq.push({current_idx + 2, idx});
            }            
            
            current_idx++;

            while(!waitq.empty() && waitq.top().first <= current_idx){
                auto wait_char = waitq.top();
                waitq.pop();
                pq.push({freq[wait_char.second], wait_char.second});
            }
        }
        return ans;
    }
};