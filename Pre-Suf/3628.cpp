class Solution {
public:
    long long count(string &s1, string s2, int m, int n, vector<vector<long long>>& memo){
        if (n == 0) return 1;
        if (m == 0) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        if (s1[m-1] == s2[n-1])
            return memo[m][n] = count(s1, s2, m-1, n-1, memo) + count(s1, s2, m-1, n, memo);
        else
            return memo[m][n] = count(s1, s2, m-1, n, memo);
    }

    long long numOfSubsequences(string s) {
        long long res = 0;
        int n = s.size();

        // 0. consider no insertion (at most one insertion)
        {
            vector<vector<long long>> memo0(n+1, vector<long long>(4, -1));
            res = max(res, count(s, "LCT", n, 3, memo0));
        }

        // try inserting only the useful letters L, C, T at every possible position 0..n
        vector<char> temp = {'L', 'C', 'T'};
        for (int i = 0; i <= n; ++i) {           // allow inserting at the end as well
            for (char ch : temp) {
                string s2 = s;
                s2.insert(s2.begin() + i, ch);
                int m = (int)s2.size();
                vector<vector<long long>> memo(m+1, vector<long long>(4, -1));
                long long curr = count(s2, "LCT", m, 3, memo); // pass m (s2 length)
                res = max(res, curr);
            }
        }
        return res;
    }
};
