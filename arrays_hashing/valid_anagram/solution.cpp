/*

Brute Force: Take one char at a time from one string and compare with the others from the other string.

Better Solution: Sort both of the string and then compare if the same.

Optimal Solution: Use hashmap, traverse first string with ++ and then traverse second string with --, then check if any != 0, return false else true.

*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mpp;
        for (char c: s) {
            mpp[c]++;
        }

        for (char c: t) {
            mpp[c]--;
        }

        for (auto it: mpp) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};