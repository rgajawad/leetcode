class MyCalendar {
private:
    map<int,int> mp;
public:
    MyCalendar() {

    }

    // [10, 20] [15, 25]
    
    bool book(int startTime, int endTime) {
        auto iter = mp.lower_bound(startTime);
        if(iter != mp.begin()) iter = prev(iter);
        while(iter != mp.end()){
            if(endTime > iter->first && startTime < iter->second) return false;
            iter++;
        }
        mp[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */