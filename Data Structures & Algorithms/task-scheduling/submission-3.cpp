class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char c : tasks){
            freq[c - 'A']++;
        }

        priority_queue<int> q;
        for(int i = 0; i < 26; i++){
            if(freq[i]){
                q.push(freq[i]);
            }
        }

        //{time, count};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitq;
        int current = 0;
        while(!q.empty() || !waitq.empty()){
            if(!q.empty()){
                int count = q.top();
                q.pop();
                if(count > 1){
                    waitq.push({current + n + 1, count - 1});
                }                
                current = current + 1;                
            }else{
                current = waitq.top().first;
            }
            while(!waitq.empty() && waitq.top().first <= current){
                q.push(waitq.top().second);
                waitq.pop();
            }
        }
        return current;
    }
};
