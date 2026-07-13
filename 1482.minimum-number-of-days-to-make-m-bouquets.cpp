/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 *
 * https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
 *
 * algorithms
 * Medium (55.36%)
 * Likes:    5826
 * Dislikes: 326
 * Total Accepted:    546.5K
 * Total Submissions: 963K
 * Testcase Example:  '[1,10,3,10,2]\n3\n1'
 *
 * You are given an integer array bloomDay, an integer m and an integer k.
 * 
 * You want to make m bouquets. To make a bouquet, you need to use k adjacent
 * flowers from the garden.
 * 
 * The garden consists of n flowers, the i^th flower will bloom in the
 * bloomDay[i] and then can be used in exactly one bouquet.
 * 
 * Return the minimum number of days you need to wait to be able to make m
 * bouquets from the garden. If it is impossible to make m bouquets return
 * -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
 * Output: 3
 * Explanation: Let us see what happened in the first three days. x means
 * flower bloomed and _ means flower did not bloom in the garden.
 * We need 3 bouquets each should contain 1 flower.
 * After day 1: [x, _, _, _, _]   // we can only make one bouquet.
 * After day 2: [x, _, _, _, x]   // we can only make two bouquets.
 * After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
 * Output: -1
 * Explanation: We need 3 bouquets each has 2 flowers, that means we need 6
 * flowers. We only have 5 flowers so it is impossible to get the needed
 * bouquets and we return -1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
 * Output: 12
 * Explanation: We need 2 bouquets each should have 3 flowers.
 * Here is the garden after the 7 and 12 days:
 * After day 7: [x, x, x, x, _, x, x]
 * We can make one bouquet of the first three flowers that bloomed. We cannot
 * make another bouquet from the last three flowers that bloomed because they
 * are not adjacent.
 * After day 12: [x, x, x, x, x, x, x]
 * It is obvious that we can make two bouquets in different ways.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * bloomDay.length == n
 * 1 <= n <= 10^5
 * 1 <= bloomDay[i] <= 10^9
 * 1 <= m <= 10^6
 * 1 <= k <= n
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
private:
    bool can(vector<int>& bloomDay, int m, int k, int days){
        int adjacentFlowers = 0;
        int bouquets = 0;
        for(int b : bloomDay){
            if(b <= days){
                adjacentFlowers++;
                if(adjacentFlowers == k){
                    bouquets += 1;
                    adjacentFlowers = 0;
                }
            }
            else{
                adjacentFlowers = 0;
            }
        }
        return bouquets >= m;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int mn = bloomDay[0];
        int mx = bloomDay[0];
        for(int b : bloomDay){
            mn = min(b, mn);
            mx = max(b, mx);
        }
        int left = mn;
        int right = mx;
        bool flag = false;
        while(left < right){
            int mid = left + (right-left)/2;
            if(can(bloomDay, m, k, mid)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
};
// @lc code=end

