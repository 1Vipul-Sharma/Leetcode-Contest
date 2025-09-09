class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n+1, INT_MIN), suff(n+1, INT_MIN);
        for(int i = 1; i <= n; i++) {
            pre[i] = max(pre[i-1], nums[i-1]);
        }
        for(int i = n-2; i >= 0; i--) {
            suff[i] = max(suff[i+1], nums[i+1]);
        }
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            if(pre[i] > nums[i] && suff[i] > nums[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};