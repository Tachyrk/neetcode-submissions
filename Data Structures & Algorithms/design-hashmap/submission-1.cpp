class MyHashMap {
public:
    vector<int*> mp = vector<int*>(1001, nullptr);;   
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int offset = key % 1000;
        int entry = key / 1000;
        if(mp[entry] == nullptr){
            mp[entry] = new int[1000];
            fill(mp[entry], mp[entry] + 1000, -1);
        }
        mp[entry][offset] = value;
    }
    
    int get(int key) {
        int offset = key % 1000;
        int entry = key / 1000;
        if(mp[entry] == nullptr){
            return -1;
        }
        return mp[entry][offset];
    }
    
    void remove(int key) {
        int offset = key % 1000;
        int entry = key / 1000;
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