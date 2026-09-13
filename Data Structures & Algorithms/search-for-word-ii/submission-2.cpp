class Solution {
public:
    struct TRIE{
        string word;
        TRIE* child[26];
        TRIE(){
            word = "";          
            for(int i = 0; i < 26; i++) child[i] = nullptr;
        }
        ~TRIE(){
            for(int i = 0; i < 26; i++) delete child[i];
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TRIE* root = new TRIE();
        vector<string> ans;

        auto update = [&](TRIE* node, string& str)->void{           
            int n = str.size();
            for(int i = 0; i < n; i++){
                int idx = str[i] - 'a';
                if(!node->child[idx]){
                    node->child[idx] = new TRIE();
                }
                node = node->child[idx];
            }
            node->word = str;
        };

        int x_dir[4] = {1, 0, -1, 0};
        int y_dir[4] = {0, 1, 0, -1};
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));   
        auto search = [&](auto &self,TRIE* node, int x, int y)->TRIE*{             
            visited[x][y] = true;            
            
            if(node->word != ""){
                ans.push_back(node->word);
                node->word.clear();
            }
            for(int nd = 0; nd < 4; nd++){
                int newx = x + x_dir[nd];
                int newy = y + y_dir[nd];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newx][newy]){
                    int child_idx = board[newx][newy] - 'a';
                    if(node->child[child_idx]){
                         node->child[child_idx] = self(self, node->child[child_idx], newx, newy);
                    }                   
                }
            }
            visited[x][y] = false;           
            bool need_delete = true;
            for(int i = 0; i < 26; i++){
                if(node->child[i]){
                    need_delete = false;
                }
            }
            if(need_delete){
                delete node;
                return nullptr;
            }

            return node;
        };

        for(auto &str : words) update(root, str);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = board[i][j] - 'a';
                if(root->child[idx]) {
                    // ✅ 修正：在外層也用回傳值更新 root 的子節點
                    root->child[idx] = search(search, root->child[idx], i, j);
                }
            }
        }    
        
        delete root;
        return ans;
    }
};
