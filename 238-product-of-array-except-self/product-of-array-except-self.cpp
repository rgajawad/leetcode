class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int L = 1;
        vector<int> answer(n);
        vector<int> prefix(n);
        for(int i = 0; i < n; i++){
            prefix[i] = L;
            L *= nums[i];

        }

        int R = 1;
        vector<int> suffix(n);
        for(int i = n-1; i >= 0; i--){
            suffix[i] = R;
            R *= nums[i];
        }
        
        for(int i = 0; i < n; i++){
            answer[i] = prefix[i]*suffix[i];
        }
        return answer;
    }
};