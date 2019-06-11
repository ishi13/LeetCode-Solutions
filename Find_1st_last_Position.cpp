/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v{-1, -1};
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                v[0] = i;
                break;
            }
        }
        if(v[0] == -1)
            return v;
            for(int j = nums.size() - 1 ; j >= 0 ; j--){
             if(nums[j] == target){
                v[1] = j;
                break;
            }
        }
      
        return v;
    }
};
