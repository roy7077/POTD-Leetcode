// Time complexity - O(N)
// Space complexity- O(N*2)
class Solution {
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        int n=intervals.size();
        
        //non overlap intervals which comes before new interval
        while(i<n and intervals[i][1]<newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
        //dealing with NEW interval and overlap intervals
        vector<int> MI=newInterval;
        while(i<n and intervals[i][0]<=newInterval[1])
        {
            MI[0]=min(intervals[i][0],MI[0]);
            MI[1]=max(intervals[i][1],MI[1]);
            i++;
        }
        
        ans.push_back(MI);
        
        // pushing rest non overlaping intervals
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans; 
    }
};