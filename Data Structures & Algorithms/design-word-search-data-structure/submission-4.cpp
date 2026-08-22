class WordDictionary {
public:
    struct TRIE{
        TRIE* child[26];
        bool isEnd;
        TRIE(){
            for(int i = 0; i < 26; i++){
                child[i] = nullptr;
            }
            isEnd = false;
        }
        ~TRIE(){
            for(int i = 0; i < 26; i++){
                delete child[i];
            }
        }
    };

    TRIE* head;
    WordDictionary() {
        head = new TRIE();
    }
    
    void addWord(string word) {
        TRIE* current = head;
        for(char c : word){
            int next = c - 'a';
            if(!current->child[next]){
                current->child[next] = new TRIE();
            }
            current = current->child[next];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {        
        auto dfs = [&](auto &self, TRIE* current, int idx) ->bool{
            if(!current) return false;
            if(idx == word.size() && current->isEnd) return true;
            if(idx == word.size()) return false;
            int next = word[idx] - 'a';
            if(word[idx] == '.'){
                for(int i = 0; i < 26; i++){
                    if(current->child[i]){
                       if(self(self, current->child[i], idx + 1)) return true;
                    }
                }
            }else{                
                if(current->child[next]){
                    return self(self, current->child[next], idx + 1);
                }
            }
            return false;
        };

        return dfs(dfs, head, 0);
    }
};
