/*
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

 

Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8
*/


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        int i;
        for(i = nums.size() - 3 ; i >= 0 ; i--)
            if(nums[i] + nums[i + 1] > nums[i + 2])
         return(nums[i] + nums[i + 1] + nums[i + 2]);
                    
        return 0;
    }
};
