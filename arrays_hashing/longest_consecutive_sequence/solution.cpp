/*

    class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) {
                return 0;
            }
            sort(nums.begin(), nums.end());
            int currentConsecutiveSequence = 1;
            int longestConsecutiveSequence = 0;
            for (int i=1; i<n; i++){
                if (nums[i] != nums[i-1]){
                    if (nums[i] == nums[i-1] + 1) {
                        currentConsecutiveSequence++;
                    } else {
                        longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                        currentConsecutiveSequence = 1;
                    }
                }
            }
            return max(longestConsecutiveSequence, currentConsecutiveSequence);
        }
    };

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};