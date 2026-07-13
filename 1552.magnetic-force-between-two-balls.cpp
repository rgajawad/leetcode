/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 *
 * https://leetcode.com/problems/magnetic-force-between-two-balls/description/
 *
 * algorithms
 * Medium (71.21%)
 * Likes:    3249
 * Dislikes: 276
 * Total Accepted:    233.1K
 * Total Submissions: 322.5K
 * Testcase Example:  '[1,2,3,4,7]\n3'
 *
 * In the universe Earth C-137, Rick discovered a special form of magnetic
 * force between two balls if they are put in his new invented basket. Rick has
 * n empty baskets, the i^th basket is at position[i], Morty has m balls and
 * needs to distribute the balls into the baskets such that the minimum
 * magnetic force between any two balls is maximum.
 * 
 * Rick stated that magnetic force between two different balls at positions x
 * and y is |x - y|.
 * 
 * Given the integer array position and the integer m. Return the required
 * force.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: position = [1,2,3,4,7], m = 3
 * Output: 3
 * Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the
 * magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is
 * 3. We cannot achieve a larger minimum magnetic force than 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: position = [5,4,3,2,1,1000000000], m = 2
 * Output: 999999999
 * Explanation: We can use baskets 1 and 1000000000.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == position.length
 * 2 <= n <= 10^5
 * 1 <= position[i] <= 10^9
 * All integers in position are distinct.
 * 2 <= m <= position.length
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    bool can(vector<int>& position, int m, int diff){
        if(diff == 0) return true;
        int currPos = 1;
        int prevPos = 0;
        int ballsPlaced = 1;
        while(currPos < position.size()){
            if(position[currPos] - position[prevPos] < diff){
                currPos += 1;
            }
            else{
                ballsPlaced += 1;
                if(ballsPlaced == m) return true;
                prevPos = currPos;
                currPos+=1;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n = position.size();
        int left = 0; 
        int right = position[n-1] - position[0];
        while(left < right){
            int mid = left + (right - left + 1)/2;
            if(can(position, m, mid)){
                left = mid;
            }
            else{
                right = mid-1;
            }
        }
        return left;

    }
};
// @lc code=end

