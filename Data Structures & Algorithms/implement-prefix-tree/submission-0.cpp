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
    };
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
        int n = word.size();
        int idx = 0;
        TRIE* current = head;
        while(current && idx < n){
            int next = word[idx] - 'a';
            if(!current->child[next]) break;
            current = current->child[next];
            idx++;
        }
        if(current && (idx == n) && current->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        int idx = 0;
        TRIE* current = head;
        while(current && idx < n){
            int next = prefix[idx] - 'a';
            if(!current->child[next]) break;
            current = current->child[next];
            idx++;
        }
        if(idx == n) return true;
        return false;
    }
};
