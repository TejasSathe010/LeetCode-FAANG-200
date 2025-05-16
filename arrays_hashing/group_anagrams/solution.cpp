class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return { { } };
        unordered_map<string, vector<string>> mpp;
        for (auto strg: strs) {
            string sortedKey = strg;
            sort(sortedKey.begin(), sortedKey.end());
            mpp[sortedKey].push_back(strg);
        }
        vector<vector<string>> result;
        for (auto mp: mpp) {
            result.push_back(mp.second);
        }
        return result;
    }
};