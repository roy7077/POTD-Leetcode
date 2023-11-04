// Time complexity - O(N)
// Space complexity -O(1)
class Solution {
    public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int l=-1e9;
        for(auto it:left)
        l=max(l,it);
        
        int r=1e9;
        for(auto it:right)
        r=min(r,it);
        
        int ans1=l-0;
        int ans2=n-r;
        
        return max(ans1,ans2);
    }
};