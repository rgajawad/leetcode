/*

s1:[ ]
s2:[ ]

*/
class MinStack {
public:
    stack<int> s1;
    stack<int> min_so_far;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty()){
            min_so_far.push(val);
        }
        else{
            if(val <= min_so_far.top()){
                min_so_far.push(val);
            }
        }
        s1.push(val);
    
    }
    
    void pop() {
       int val = s1.top(); 
       s1.pop();
       if(val == min_so_far.top()){
            min_so_far.pop();
       }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min_so_far.top();     
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