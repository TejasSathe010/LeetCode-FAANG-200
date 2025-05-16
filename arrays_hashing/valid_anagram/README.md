# Valid Anagram

> **Pattern:** Arrays & Hashing  
> [LeetCode problem](https://leetcode.com/problems/valid-anagram/)

## Intuition

| Approach | Idea |
|----------|------|
| Brute-force | Take one char at a time from one string and compare with the others from the other string. |
| Better | Sort both of the string and then compare if the same. |
| Optimal | Use hashmap, traverse first string with ++ and then traverse second string with --, then check if any != 0, return false else true. |

## Complexity

| Approach  | Time | Space |
|-----------|------|-------|
| Brute-force | O(N^2) | O(1) |
| Better | 2*O(NlogN) | O(1) |
| Optimal | 2*O(N) | O(N) |

