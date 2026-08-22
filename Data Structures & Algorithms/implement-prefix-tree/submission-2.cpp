class PrefixTree {
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
    // 回傳字串走到最後停在哪個節點，如果半路斷掉就回傳 nullptr
    TRIE* findNode(string& word) {
        TRIE* current = head;
        for (char c : word) {
            int next = c - 'a';
            if (!current->child[next]) return nullptr;
            current = current->child[next];
        }
        return current;
    }
    TRIE* head;
    PrefixTree() {    
        head = new TRIE();  
    }
    
    void insert(string word) {
        int n = word.size();
        int idx = 0;
        TRIE* current = head;
        while(idx < n){
            int next = word[idx] - 'a';
            if(!current->child[next]){
                TRIE* newnode = new TRIE();
                current->child[next] = newnode;
            }
            current = current->child[next];
            idx++;           
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TRIE* result = findNode(word);
        return (result && result->isEnd);
    }
    
    bool startsWith(string prefix) {
        TRIE* result = findNode(prefix);
        return (result);
    }
};
