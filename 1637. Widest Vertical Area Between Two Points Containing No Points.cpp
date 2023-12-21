// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int maxi=-1;
        for(int i=0;i<points.size()-1;i++)
        maxi=max(maxi,(points[i+1][0]-points[i][0]));
        return maxi;
    }
};