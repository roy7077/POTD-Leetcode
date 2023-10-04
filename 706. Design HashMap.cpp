class MyHashMap {
public:
    
    const static int size = 10000;
    vector<vector<pair<int,int>>> v;
    
    MyHashMap() {
        v.resize(size);
    }

    
    void put(int key, int value) {
    
        for(auto& it:v[key%size])
        {
            if(it.first==key)
            {
                it.second=value;
                return ;
            }
        }
        
        v[key%size].emplace_back(key,value);
    }
    
    int get(int key) {
            
        for(auto& it:v[key%size])
        {
            if(it.first==key)
            return it.second;
        }
        
        return -1;
    }
    
    
     void remove(int key) {
        auto& pairs = v[key%size];
        for(auto i=pairs.begin(); i!= pairs.end(); i++)
        {
            if(i->first==key) { pairs.erase(i); return; }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
