class Solution {
public:
    
string res="";

void backtrack(string &s, int start, int cuts, int k, vector<string> &curr) {
    int n = s.size();

    // If we reached end of string
    if (start == n) {
        if (cuts == k) {
            for(auto &ele:curr){
                res=max(res,ele);
            }
        }
        return;
    }

    for (int end = start; end < n; end++) {
        string piece = s.substr(start, end - start + 1);
        curr.push_back(piece);

        // If adding this piece increases cuts (only if not last piece yet)
        int newCuts = cuts;
        if (end < n - 1) newCuts++;

        // Only recurse if still possible to reach k cuts
        if (newCuts <= k)
            backtrack(s, end + 1, newCuts, k, curr);

        curr.pop_back();
    }
}


    string answerString(string s, int k) {
        vector<string> curr;
        backtrack(s, 0, 0, k-1, curr);
        return res;
    }
};