/*
Brute Force: Check all possible combination of two numbers and check there sum if equals to target.

Better Solution: Use hashmap to store the seen values and then when checking the new number find out the complement (target - num),  and check if the complement is present or not in the seen numbers.

Optimal Solution: Use two pointers method, Sort the array and check from different ends if nums[low] + nums[high] == target. 
*/


#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size()-1;

        while (low < high) {
            long long total = nums[low] + nums[high];
            if (total == target) { 
                return {low, high};
            } else if (total > target) {
                high--;
            } else {
                low++;
            }
        }
        return {-1, -1};
    }
};