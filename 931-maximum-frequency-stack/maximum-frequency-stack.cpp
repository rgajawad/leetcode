/*


0 

1 -> 5 , 7, 4
2 ->5, 7
3-> 5
*/

class FreqStack {
private:
    int maxFreq;
    unordered_map<int,int> num2freq;
    unordered_map<int,vector<int>> freq2num;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        num2freq[val]++;
        maxFreq = max(num2freq[val], maxFreq);
        int freq = num2freq[val];
        freq2num[freq].push_back(val);
    }
    
    int pop() {
        int val = freq2num[maxFreq].back();
        freq2num[maxFreq].pop_back();
        num2freq[val]--;
        if(freq2num[maxFreq].empty()) {
            freq2num.erase(maxFreq);
            maxFreq--;  
        }
       return val;


    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */