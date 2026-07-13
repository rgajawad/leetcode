/*
 * @lc app=leetcode id=2454 lang=cpp
 *
 * [2454] Next Greater Element IV
 *
 * https://leetcode.com/problems/next-greater-element-iv/description/
 *
 * algorithms
 * Hard (39.86%)
 * Likes:    758
 * Dislikes: 12
 * Total Accepted:    19.7K
 * Total Submissions: 46.7K
 * Testcase Example:  '[2,4,0,9,6]'
 *
 * You are given a 0-indexed array of non-negative integers nums. For each
 * integer in nums, you must find its respective second greater integer.
 * 
 * The second greater integer of nums[i] is nums[j] such that:
 * 
 * 
 * j > i
 * nums[j] > nums[i]
 * There exists exactly one index k such that nums[k] > nums[i] and i < k <
 * j.
 * 
 * 
 * If there is no such nums[j], the second greater integer is considered to be
 * -1.
 * 
 * 
 * For example, in the array [1, 2, 4, 3], the second greater integer of 1 is
 * 4, 2 is 3, and that of 3 and 4 is -1.
 * 
 * 
 * Return an integer array answer, where answer[i] is the second greater
 * integer of nums[i].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,4,0,9,6]
 * Output: [9,6,6,-1,-1]
 * Explanation:
 * 0th index: 4 is the first integer greater than 2, and 9 is the second
 * integer greater than 2, to the right of 2.
 * 1st index: 9 is the first, and 6 is the second integer greater than 4, to
 * the right of 4.
 * 2nd index: 9 is the first, and 6 is the second integer greater than 0, to
 * the right of 0.
 * 3rd index: There is no integer greater than 9 to its right, so the second
 * greater integer is considered to be -1.
 * 4th index: There is no integer greater than 6 to its right, so the second
 * greater integer is considered to be -1.
 * Thus, we return [9,6,6,-1,-1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,3]
 * Output: [-1,-1]
 * Explanation:
 * We return [-1,-1] since neither integer has any integer greater than it.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <deque> 
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> s1;
        stack<int> s2;
        deque<int> dq;
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            while(s2.size() && nums[i] > nums[s2.top()]){
                int prev = s2.top();
                s2.pop();
                res[prev] = nums[i];
            }
            while(s1.size() && nums[i] > nums[s1.top()]){
                int prev = s1.top();
                s1.pop();
                dq.push_front(prev);
            }
            while(dq.size()){
                s2.push(dq.front());
                dq.pop_front();
            }
            s1.push(i);
        }
        return res;
    }
};
// @lc code=end

