/*
unordered map : key -> set 

*/
class TimeMap {
private:
    unordered_map<string, map<int, string>> mp; 
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;

    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        auto iter = mp[key].upper_bound(timestamp);
        if(iter == mp[key].begin()) return "";
        iter = prev(iter);
        return iter->second;
        
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */