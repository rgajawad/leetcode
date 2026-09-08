class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        char maxChar= s[0]; 
        int charFreq =1;
        int maxCount = 1;
        int i, j;
        i = 0, j = 0;
        unordered_map<char, int> char2freq;
        map<int, set<char>> mp;
        while(j < n){
            char2freq[s[j]]++;
            mp[char2freq[s[j]]].insert(s[j]);
            charFreq = mp.rbegin()->first;
            while(j - i + 1 - charFreq > k){
                int oldFreq = char2freq[s[i]];
                mp[oldFreq].erase(s[i]);
                char2freq[s[i]]--; 
                if(oldFreq -1 > 0 ) mp[oldFreq-1].insert(s[i]);
                i++;
                charFreq = mp.rbegin()->first;
            }
            maxCount = max(maxCount, j - i + 1);
            j++;

        }
        return maxCount;
        
    }
};