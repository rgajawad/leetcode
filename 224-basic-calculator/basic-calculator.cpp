/**
    1+1-2+ 3
    1+2-(2+2)
    -1


**/

class Solution {


public:
    int calculate(string s) {
        stack<long long> st;
        int i = 0;
        int n = s.size();
        long long runningSum = 0;
        int sign = 1;
        while(i < n){
            if(s[i] == '(') {
                st.push(runningSum);
                st.push(sign);
                runningSum = 0;
                sign = 1;
            }
            else if(s[i] == '+') {
               sign = 1;
            }
            else if(s[i] == '-'){
                sign = -1;
            }
            else if(isdigit(s[i])){
                int j = i;
                while(j < n  && isdigit(s[j])){
                   j++;
                }
                j--;
                long long val = stoll(s.substr(i, j - i+1));
                runningSum += sign*val;
                sign = 1;
                i = j;
            }
            else if(s[i] == ')'){
               sign = st.top(); 
               st.pop();
               runningSum *= sign;
               runningSum += st.top();
               st.pop();
            }
            i++;

        }
        return runningSum;
    }

};