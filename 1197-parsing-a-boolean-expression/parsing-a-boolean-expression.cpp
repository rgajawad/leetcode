/**
I will get the first operand -> ! or & or |

and then I will skip over the open bracket and then get the substrings separated by comma 

I will call solve over each substring and get the value and then apply the operator among all the values and then return 

and then return that value 

base case is just t or f, if t return true; if f return false 



**/
class Solution {
public:
    bool solve(string expr, int scope){
        if(expr.size() == 1){
            if(expr == "t") return true;
            if(expr == "f") return false;
        }
        vector<bool> operands;

        auto applyOper = [&](char c){
            bool res = operands[0];
            if(c == '!') return !res;
            for(int i = 1; i < operands.size(); i++){
                bool val = operands[i];
                if(c == '&') res = res && val;
                else if(c == '|') res = res || val;
            }
            return res;
        };

        char oper = expr[0];
        int i = 2;
        int j = i;
        int n = expr.size();
        int currentScope = scope;
        while(j < n){
            if(expr[j] == '('){
                currentScope++;
            }
            else if(expr[j] == ')'){
                if(currentScope > scope){
                    currentScope--;
                }
                else{
                    operands.push_back(solve(expr.substr(i, j-i), scope+1));
                    break;
                }

            }
            else if(expr[j] == ',' && currentScope == scope){
                operands.push_back(solve(expr.substr(i, j-i), scope+1));
                i = j+1;

            }
            j++;
        }
        
       return applyOper(oper);

    }

    bool parseBoolExpr(string expression) {
        return solve(expression, 0);
    }
};