class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";
        for(char c : s){
            if(!isalnum(c)) continue;
            newString += tolower(c);
        }
        cout << newString << endl;
        int i, j;
        i = 0, j = newString.size()-1;
        while(i < j){
            if(newString[i] != newString[j]) return false;
            i++, j--;
        }
        return true;
        
    }
};