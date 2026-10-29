class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> num2idx;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(num2idx.count(val)) return false;
        num2idx[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!num2idx.count(val)) return false;
        int idx = num2idx[val];
        num2idx[nums.back()] = idx;
        swap(nums[idx], nums[nums.size()-1]);
        nums.pop_back();
        num2idx.erase(val);
        return true;

    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */