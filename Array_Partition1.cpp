/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, sum = 0, imin;
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1 || nums.size() == 2)
                return nums[0];
        for(i = 0; i < nums.size() - 1; i++){
             imin = min(nums[i], nums[i+1]);
             sum += imin;
             i++;
        }
         
        return sum;
    }
};
