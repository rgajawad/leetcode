class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int res = 1;
        for(int i = 0; i < n; i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    mx = max(mx, dp[j]);
            }
            dp[i] = 1 + mx;
            res = max(res, dp[i]);
        }
        return res;
    }
};