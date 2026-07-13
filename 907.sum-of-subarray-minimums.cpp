/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    9379
 * Dislikes: 751
 * Total Accepted:    474.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over
 * every (contiguous) subarray of arr. Since the answer may be large, return
 * the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,1,2,4]
 * Output: 17
 * Explanation: 
 * Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
 * [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 * Sum is 17.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [11,81,94,43,3]
 * Output: 444
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 3 * 10^4
 * 
 * 
 * 
 * 
 *  3 1 2 4
 *  Ans: 1*3 + 1*4 + 2*2 + (2)*1 *(3)*1  
 *  [1, 2, 4]
 * 
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;




// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;
        for(int i = 0; i <= n; i++){
            int currentHeight = i == n ? 0 : arr[i];
            while(st.size() && currentHeight < arr[st.top()]){
                int index = st.top();
                st.pop();

                int leftBoundary = st.empty() ? -1: st.top();

                long long leftChoices = index - leftBoundary;
                long long rightChoices = i - index;

                long long contribution = static_cast<long long>(arr[index])*leftChoices*rightChoices;

                sum = (sum + contribution)%MOD;

            }
            st.push(i);
        }
        return sum;
        
    }
};
// @lc code=end

