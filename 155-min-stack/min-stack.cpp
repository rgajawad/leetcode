/*

s1:[ ]
s2:[ ]


    

*/
class MinStack {
private:
    stack<pair<int,int>> s1;
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty()){
            s1.push({val, val});
            return;
        }
        int minSoFar = s1.top().second;
        s1.push({val, min(val, minSoFar)});
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return s1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */