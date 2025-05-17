class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                el = nums[i];
                count = 1;
            } else if (nums[i] == el) {
                count++;
            } else {
                count--;
            }
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) {
                cnt++;
            }
        }
        return cnt > int(nums.size()/2) ? el : -1;
    }
};