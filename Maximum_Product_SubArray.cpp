/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = nums[0];
        int imax = nums[0];
        int imin = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] <= 0){
                int t = imax;
                imax = imin;
                imin = t;
              }
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin * nums[i]);
            cout << imax << endl;
            cout << imin << endl;
            m = max(m, imax);
        }
        return m;
    }
};
