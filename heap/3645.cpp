// 3644
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({limit[i], value[i]});
        }

        // sort by limit ascending
        sort(arr.begin(), arr.end());

        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        long long res = 0;

        for (auto &p : arr) {
            int lim = p.first;
            int val = p.second;

            pq.push(val);
            if ((int)pq.size() >= lim) {
                // if we exceed capacity (limit - 1), pop smallest
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};
