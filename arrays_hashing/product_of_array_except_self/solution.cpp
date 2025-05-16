/*

Optimal Soution:

    class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n, 1);

            for (int i = 1; i < n; i++) {
                res[i] = res[i - 1] * nums[i - 1];
            }
            
            int postfix = 1;
            for (int i = n - 1; i >= 0; i--) {
                res[i] *= postfix;
                postfix *= nums[i];
            }
            return res;
        }
    };

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n, 1);
        for (int i = 1; i < n; i++) {
            pre[i] = nums[i - 1] * pre[i-1];
        }

        vector<int> suff(n, 1);
        for (int i = n-2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i+1];
        }

    
        vector<int> result(n, 1);
        for (int i = 0; i < n; i++) {
            result[i] = pre[i] * suff[i];
        }
        return result;
    }
};