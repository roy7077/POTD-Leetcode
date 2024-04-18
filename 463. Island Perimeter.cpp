// Time complexity - O(N*M)
// Space complexity- O(1)
class Solution {
    public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                // count if adj grid is border or water
                if(grid[i][j])
                {
                    if(i-1<0 or grid[i-1][j]==0)
                    ans++;

                    if(j-1<0 or grid[i][j-1]==0)
                    ans++;

                    if(i+1>=n or grid[i+1][j]==0)
                    ans++;

                    if(j+1>=m or grid[i][j+1]==0)
                    ans++;
                }
            }
        }
        return ans;
    }
};