class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;

        // Store positions of each number
        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        vector<int> res(queries.size(), -1);

        for (int q = 0; q < queries.size(); q++) {
            int j = queries[q];
            int val = nums[j];
            
            // If this number appears only once → no duplicate
            if (positions[val].size() == 1) continue;

            auto &pos = positions[val];

            // Find closest index to j
            auto it = lower_bound(pos.begin(), pos.end(), j);
            int ans = n; // max possible distance

            if (it != pos.end() && *it != j) {
                ans = min(ans, abs(*it - j));
            }
            if (it != pos.begin()) {
                --it;
                ans = min(ans, abs(*it - j));
            }

            // Circular wrap-around
            ans = min(ans, j + n - pos.front());  // wrap left to first
            ans = min(ans, pos.back() + n - j);   // wrap right to last

            res[q] = ans;
        }

        return res;
    }
};
©leetcode