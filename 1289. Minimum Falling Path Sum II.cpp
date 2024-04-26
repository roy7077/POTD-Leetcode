
// Memoization
class Solution {
    public:
    int help(vector<vector<int>>& grid,int i,int preCol,vector<vector<int>>& memo)
    {
        //base case
        if(i>=grid.size())
        return 0;
        
        if(memo[i][preCol+1]!=-1)
        return memo[i][preCol+1];
        
        //recursive calls
        //and small calculation
        int mini=1e9;
        for(int j=0;j<grid[0].size();j++)
        {
            if(j==preCol)
            continue;
            
            int call=grid[i][j]+help(grid,i+1,j,memo);
            mini=min(mini,call);
        }
        return memo[i][preCol+1]=mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(),vector<int>(grid.size()+1,-1));
        return help(grid,0,-1,memo);
    }
};


// Tabulation
class Solution {
    public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=n;j++)
            {
                int minSum=1e9;
                for(int k=0;k<n;k++)
                {
                    int sum=0;
                    if(k==j-1)
                    continue;
                    
                    sum+=grid[i][k];
                    if(i+1<n)
                    sum+=dp[i+1][k+1];
                    
                    minSum=min(minSum,sum);
                }
                dp[i][j]=minSum;
            }
        }
        return dp[0][0];
    }
};


// Space optimized
class Solution {
    public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> next(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(n+1,0);
            for(int j=0;j<=n;j++)
            {
                int minSum=1e9;
                for(int k=0;k<n;k++)
                {
                    int sum=0;
                    if(k==j-1)
                    continue;
                    
                    sum+=grid[i][k];
                    if(i+1<n)
                    sum+=next[k+1];
                    
                    minSum=min(minSum,sum);
                }
                curr[j]=minSum;
            }
            next=curr;
        }
        return next[0];
    }
};