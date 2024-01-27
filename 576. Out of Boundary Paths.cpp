// DFS
// MEMOIZATION
class Solution {
    public:
    int mod=1e9+7;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    int help(int& n,int& m,int maxMove,int i,int j,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(i<0 or i>=n or j<0 or j>=m)
        return 1;
        
        if(maxMove==0)
        return 0;
        
        if(memo[i][j][maxMove]!=-1)
        return memo[i][j][maxMove];
        
        //recursive calls
        //small calculation
        int cnt=0;
        for(int k=0;k<4;k++)
        {
            int r=i+x[k];
            int c=j+y[k];
            cnt=(cnt+help(n,m,maxMove-1,r,c,memo)%mod)%mod;
        }
        
        return memo[i][j][maxMove]=cnt;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return help(m,n,maxMove,startRow,startColumn,memo);
    }
};
