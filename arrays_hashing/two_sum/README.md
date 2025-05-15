# Two Sum

> **Pattern:** Arrays & Hashing  
> [LeetCode problem](https://leetcode.com/problems/two-sum/)

## Intuition

| Approach | Idea |
|----------|------|
| Brute-force | Check all possible combination of two numbers and check there sum if equals to target.|
| Better | Use hashmap to store the seen values and then when checking the new number find out the complement (target - num),  and check if the complement is present or not in the seen numbers.|
| Optimal | Use two pointers method, Sort the array and check from different ends if nums[low] + nums[high] == target.|

## Complexity

| Approach  | Time | Space |
|-----------|------|-------|
| Brute-force | O(N^2) | O(1) |
| Better | O(N) | O(N) |
| Optimal | O(N) | O(1) |

