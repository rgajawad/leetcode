/*

freq -> []

1-> []
2-> []
3->[]

max_freq_so_far

key -> freq



*/
class FreqStack {
private:
    unordered_map<int,vector<int>> freq2arr;
    unordered_map<int,int> num2freq;
    int max_freq_so_far = 0;


public:
    FreqStack() {
        
    }
    
    void push(int val) {
       num2freq[val]+=1; 
       int freq = num2freq[val];
       freq2arr[freq].push_back(val);
       max_freq_so_far = max(max_freq_so_far, freq);
    }
    
    int pop() {
        int popped_val = freq2arr[max_freq_so_far].back();
        freq2arr[max_freq_so_far].pop_back();
        num2freq[popped_val] -= 1;
        if(freq2arr[max_freq_so_far].empty()){
            freq2arr.erase(max_freq_so_far);
            max_freq_so_far -= 1;
        }
        return popped_val;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */