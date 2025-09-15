class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    int n;

    int dfs(int i, int cnt, int parity, vector<int>& nums) {
        if (i == n) return 0;
        if (memo[i][cnt][parity] != -1) return memo[i][cnt][parity];

        long long res = 0;

        // Option 1: skip nums[i]
        res += dfs(i + 1, cnt, parity, nums);

        // Option 2: take nums[i]
        int currParity = nums[i] % 2;
        if (cnt == 0) {
            // first element in subsequence
            res += 1; // subsequence containing only nums[i]
            res += dfs(i + 1, 1, currParity, nums);
        } else {
            if (currParity == parity) {
                if (cnt < 2) { // can still add
                    res += 1; // subsequence ending here
                    res += dfs(i + 1, cnt + 1, parity, nums);
                }
            } else {
                res += 1; // subsequence ending here
                res += dfs(i + 1, 1, currParity, nums);
            }
        }

        return memo[i][cnt][parity] = res % MOD;
    }

    int countStableSubsequences(vector<int>& nums) {
        n = nums.size();
        memo.assign(n + 1, vector<vector<int>>(3, vector<int>(2, -1)));
        return dfs(0, 0, 0, nums) % MOD;
    }
};