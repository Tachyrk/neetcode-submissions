class MyHashMap {
public:
    vector<int*> mp = vector<int*>(1024, nullptr);  
    int MASK = 0x3FF;
    int PAGE_SIZE = 1024;
    MyHashMap() {
        
    }
    ~MyHashMap() {
    for (int* page : mp) {
            delete[] page;
        }
    }
    void put(int key, int value) {
        int offset = key & MASK;
        int entry = key >> 10;
        if(mp[entry] == nullptr){
            mp[entry] = new int[PAGE_SIZE];
            fill(mp[entry], mp[entry] + PAGE_SIZE, -1);
        }
        mp[entry][offset] = value;
    }
    
    int get(int key) {
        int offset = key & MASK;
        int entry = key >> 10;
        if(mp[entry] == nullptr){
            return -1;
        }
        return mp[entry][offset];
    }
    
    void remove(int key) {
        int offset = key & MASK;
        int entry = key >> 10;
        if(mp[entry] == nullptr){
            return;
        }
        mp[entry][offset] = -1;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */