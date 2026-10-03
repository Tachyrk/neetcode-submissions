class MyHashSet {
public:
    bitset<1000001> bs;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bs.set(key);
    }
    
    void remove(int key) {
        bs.reset(key);
    }
    
    bool contains(int key) {
        return bs.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */