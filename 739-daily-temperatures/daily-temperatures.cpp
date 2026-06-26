class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(st.size() && nums[i] > nums[st.top()]){
                result[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        } 
        return result;
    }
};