#include <unordered_map>

class LRUCache {
private:
    // 1. 節點必須同時存 key 和 val，因為淘汰尾巴時需要用 key 去 map 裡面刪資料
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> mp;
    
    // 2. 建立 Dummy Head 和 Dummy Tail
    Node* head;
    Node* tail;

    // 核心模組 1：將節點加到「最前面」(head 的下一個)
    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 核心模組 2：將某個節點拔除 (因為有 dummy nodes，絕對不會遇到 nullptr)
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // 組合技：將現有節點移到最前面
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // 組合技：拔除並回傳最後一個真實節點 (tail 的前一個)
    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // 初始化時，直接讓 dummy head 和 dummy tail 互指
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        // 如果找到了，透過 hash map 拿到 node，然後把它移到最前面
        Node* node = mp[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // 如果 key 已經存在：更新值，並移到最前面
            Node* node = mp[key];
            node->val = value;
            moveToHead(node);
        } else {
            // 如果 key 不存在：建立新節點
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);

            // 如果容量超標，淘汰最尾巴的節點
            if (mp.size() > capacity) {
                Node* tailNode = popTail();
                mp.erase(tailNode->key); // 這就是為什麼 Node 裡面必須存 key
                delete tailNode;         // 釋放記憶體
            }
        }
    }

    // 面試如果是要求高一點的 C++ 職缺，可以順手寫個解構子展現 sense
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};