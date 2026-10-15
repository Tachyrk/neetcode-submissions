class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.count("0000")) return -1;
        
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int step = 0;       
        while(!q.empty()){
            step++;
            int size = q.size();
            while(size--){
                string current = q.front();                
                q.pop();
                for(int i = 0; i < 4; i++){
                    char origin = current[i];
                    //plus 1
                    current[i] = (origin == '9') ? '0' : origin + 1;
                    if(current == target) return step;                    
                    if(!visited.count(current)){
                        visited.insert(current);
                        q.push(current);
                    }
                    //minus 1
                    current[i] = (origin == '0') ? '9' : origin - 1;
                    if(current == target) return step;
                    if(!visited.count(current)){
                        visited.insert(current);
                        q.push(current);
                    }
                    current[i] = origin;
                }
            }            
        }
        return -1;
    }
};