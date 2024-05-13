// Time complexity - O(N*M*logM)
// Space complexity- O(M)
class Solution {
    public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            col[j]+=grid[i][j];
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)
                    {
                        grid[i][j]=0;
                        col[j]--;
                    }
                    else
                    {
                        grid[i][j]=1;
                        col[j]++;
                    }
                }
            }
        }
        
        for(int j=1;j<m;j++)
        {
            if(col[j]<(n-col[j]))
            {
                for(int i=0;i<n;i++)
                grid[i][j]=grid[i][j]==1 ? 0:1;
                
            }
        }
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int dec=0;
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]==1)
                dec+=pow(2,m-j-1);
            }
            sum+=dec;
        }
        
        return sum;
    }
};

