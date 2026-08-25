class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> key2list;
        for(auto str : strs){
            vector<int> arr(26);
            string key = "";
            for(auto c : str){
                arr[c-'a']++;
            }
            for(int x : arr) key += to_string(x) + "#";
            key2list[key].push_back(str);
        }
        for(auto [_,y] : key2list){
            res.push_back(y);
        }
        return res;
        
    }
};