class Solution {
public:
    bool isValid(string s) {
        stack<char> st;    
        auto isOpen = [&](char x){
            return x == '(' || x == '[' || x == '{';
        };
        auto isMatch = [&](char x, char y){
            if(x == '(' && y == ')') return true;
            if(x == '{' && y == '}') return true;
            if(x == '[' && y == ']') return true;
            return false;
        };
        for(char c : s){
            if( isOpen(c)) st.push(c);
            else{
                if(st.empty()) return false;
                if(!isMatch(st.top(), c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};