/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (47.02%)
 * Likes:    19846
 * Dislikes: 394
 * Total Accepted:    1.6M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [2,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <stack> 
using namespace std;
// @lc code=start

/***
 * 
 * 8 6 6 7 3 8
 * 
 * 
 * [8, 5 ]
 */



class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            // if(i == n-1){
            //     maxArea = max(maxArea, nums[i]);
            // }
            while(st.size() && nums[i] < nums[st.top()]){
                int h = nums[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h*width);
            }
            st.push(i);
        }
        while(st.size()){
            int val = st.top();
            st.pop();
            int width = st.empty() ? nums.size() : nums.size() - st.top() - 1;
            maxArea = max(nums[val]*width, maxArea);
        }
        return maxArea;
    }
};
// @lc code=end

