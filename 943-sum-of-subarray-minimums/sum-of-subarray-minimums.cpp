class Solution {
private:
   vector<int> nextSmallerRight(vector<int>& nums) {
    vector<int> result(nums.size(), nums.size());
    stack<int> st; // store indices
    for(int i = 0; i < nums.size(); i++){
        while(st.size() && nums[st.top()] > nums[i]){
            result[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return result;
}

vector<int> previousSmallerLeft(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<int> st; // store indices
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(st.size() && nums[st.top()] > nums[i]){
            st.pop();
        }
        if(st.size()){
            result[i] = st.top();
        }
        st.push(i);
    }
    // TODO
    return result;
}
// 1 2 3 
// 1, 12, 123, 2, 23, 3 
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        auto nsr = nextSmallerRight(arr);
        auto psl = previousSmallerLeft(arr);
        

        // 1  3
        // 1 2 3 4
        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            long long left = i - psl[i];
            long long right = nsr[i] - i;

            long long count = left * right;
            res = (res + count * arr[i]) % MOD;
        }
        return res;
    }
};