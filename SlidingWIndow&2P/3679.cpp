class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        int n= arr.size();
        int l=0;
        set<int> d;
        unordered_map<int,int> m;
        int res=0;
        for(int r=0;r<n;r++){
            while(r-l+1-res>w){
                while(d.find(l)!=d.end()) l++;
                if(m.find(arr[l])!=m.end())
                    m[arr[l]]--;
            }
            if(m[arr[r]]+1>m){
                while(d.find(l)!=d.end()) l++;
                if(m.find(arr[l])!=m.end())
                    m[arr[l]]--;
            }
            else{
                
            }
        }
        return res;
    }
};