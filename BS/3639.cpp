class Solution {
public:
    long long countSubstringsWithStar(string &s) {
        long long n = s.size();
        long long total = n * (n + 1) / 2;
        
        long long noStar = 0;
        long long len = 0;
        
        for (char c : s) {
            if (c == '*') {
                noStar += (len * (len + 1)) / 2;
                len = 0;
            } else {
                len++;
            }
        }
        noStar += (len * (len + 1)) / 2; // last segment

        return total - noStar;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n=order.size();
        if((1LL*n*(n+1)/2)<k) return -1;
        for(int i=0;i<n;i++){
            s[order[i]]='*';
            if(countSubstringsWithStar(s)-k>=0) return i;
        }
        return -1;
    }
};