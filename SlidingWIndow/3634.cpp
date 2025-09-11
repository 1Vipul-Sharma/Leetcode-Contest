class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, longest = 1;
        for (int j = 0; j < n; j++) {
            while (i <= j && 1LL * nums[i] * k < nums[j]) {
                i++; 
            }
            longest = max(longest, j - i + 1);
        }

        return n - longest;
    }
};
