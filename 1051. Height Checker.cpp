// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp=heights;
        sort(temp.begin(),temp.end());
        
        int cnt=0;
        for(int i=0;i<temp.size();i++)
        cnt+= temp[i]!=heights[i];
        
        return cnt;
    }
};