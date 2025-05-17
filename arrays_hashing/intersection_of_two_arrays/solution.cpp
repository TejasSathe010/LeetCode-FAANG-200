class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> st(nums1.begin(), nums1.end());
        for (auto num: nums2) {
            if (st.find(num) != st.end()) {
                result.push_back(num);
                st.erase(num);
            }
        }
        return result;
    }
};