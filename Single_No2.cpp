/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      if (nums.size() == 1) 
          return nums.front();
        sort(nums.begin(), nums.end());
       for (int i = 0; i < nums.size(); i++) {
            if (i == 0 && nums[i] != nums[i+1]) 
                return nums[0];
            if (i == nums.size() - 1 && nums[i] != nums[i-1]) 
                return nums.back();
            if (i != 0 && i != nums.size() - 1 && nums[i] != nums[i-1] && nums[i] != nums[i+1]) 
                return nums[i];
        }
        return 0;
    }
};
