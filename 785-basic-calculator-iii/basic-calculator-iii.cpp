/*
"1+2*3"


2 * [st]


"2*(5+5*2)/3+(6/2+8)"
2*(5 + 5*2)

(1+ 2*2

1+2
2 + ((5+2)*3)

*/

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0; 
        stack<string> st;
        string prevOp = "+";
        while(i < n){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') prevOp = s[i];
            else if(s[i] == '('){
                if(i == 0) st.push("0");
                st.push(prevOp);
                st.push("(");
                prevOp = '+';
            }
            else if(s[i] == ')'){
                int res = 0; 
                while(st.size() && st.top() != "("){
                    string val = st.top();
                    st.pop();
                    res += stoi(val);
                }
                st.pop();
                string sign = st.top();
                st.pop();
                if(sign == "*"){
                    int val = stoi(st.top());
                    st.pop();
                    res *= val;
                }
                else if(sign == "/"){
                    int val = stoi(st.top());
                    st.pop();
                    res = val/res;
                }
                else if(sign == "-"){
                    res *= -1;
                }
                st.push(to_string(res));
            }
            else if(isdigit(s[i])){
                int j = i;
                while(j < n && isdigit(s[j])){
                    j++;
                }
                j--;
                int val = stoi(s.substr(i, j-i+1));
                if(prevOp == "*" || prevOp == "/"){
                    int prev = stoi(st.top());
                    st.pop();
                    if(prevOp == "*") st.push(to_string(prev*val));
                    else if (prevOp == "/") st.push(to_string(prev/val));
                }
                else{
                    if(prevOp == "-") val*= -1;
                    st.push(to_string(val));
                }
                prevOp = "+";
                i = j;
            }
            i++;
        }
        int res = 0;
        while(st.size()){
            res += stoi(st.top());
            st.pop();
        }
        return res;
    }
};