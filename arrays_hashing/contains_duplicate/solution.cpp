/*
Brute Force: Use @2 loops and check if any numbers repeats.

Optimal Solution: Sort the array and then check if the last element is same as the current element (return true) else (return false)

*/


#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};