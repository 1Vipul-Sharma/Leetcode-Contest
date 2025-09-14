class Solution {
public:
  inline long long C(long long n) { return (n < 2 ? 0 : (n--*(n))/2); }

  long long perfectPairs(vector<int>& nums) {
    long long ans = 0;
    map<int,int> f;
    vector<int> A;
    // count by absolute value
    for (auto n : nums) ++f[abs(n)];
    for (auto &[val,c] : f) A.push_back(val);
    if (A.empty()) return 0;
    // prefix sums of frequencies
    vector<int> p(A.size());
    p[0] = f[A[0]];
    for (int i = 1 ; i < (int)p.size() ; ++i) p[i] = p[i - 1] + f[A[i]];
    // for each distinct absolute value
    for (int i = 0 ; i < (int)A.size() ; ++i) {
      long long cnt = f[A[i]];
      // pairs among same absolute value
      ans += C(cnt);
      // Find the first index (idx) such that (A[idx] > 2*v) (use upper_bound).
      // All A[j] for i<j<idx satisfy A[j] <= 2*v and thus form perfect pairs with v.
      auto it = upper_bound(A.begin() + i + 1, A.end(), (A[i] << 1));
      int idx = (int)(it - A.begin()); // first position > 2*A[i]
      if (idx > i + 1) {
        // sum frequencies of A[i+1 .. idx-1] = p[idx-1] - p[i]
        ans += cnt * 1LL * (p[idx - 1] - p[i]);
      }
    }
    return ans;
  }
};