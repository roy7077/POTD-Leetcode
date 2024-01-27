// RECURSION
class Solution {
    public:
    int mod=1e9+7;
    int help(int n,int k)
    {
        //base case
        if(k==0)
        return 1;
        
        if(n==0)
        return 0;
        
        //recursive calls
        //small calculation
        int cnt=0;
        for(int i=0;i<=min(n-1,k);i++)
        cnt=(cnt+help(n-1,k-i))%mod;
        
        return cnt;
    }
    int kInversePairs(int n, int k) {
        return help(n,k);
    }
};

// MEMOIZATION
class Solution {
    public:
    int mod=1e9+7;
    int help(int n,int k,vector<vector<int>>& memo)
    {
        //base case
        if(k==0)
        return 1;
        
        if(n==0)
        return 0;
        
        //memo check
        if(memo[n][k]!=-1)
        return memo[n][k];
        
        //recursive calls
        //small calculation
        int cnt=0;
        for(int i=0;i<=min(n-1,k);i++)
        cnt=(cnt+help(n-1,k-i,memo))%mod;
        
        return memo[n][k]=cnt;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
        return help(n,k,memo);
    }
};


// TABULATION
class Solution {
    public:
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                
                int cnt=0;
                for(int ind=0;ind<=min(i-1,j);ind++)
                cnt=(cnt+dp[i-1][j-ind])%mod;
                
                dp[i][j]=cnt;
            }
        }
        return dp[n][k];
    }
};


// SPACE OPTIMIZED
class Solution {
    public:
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<int> pre(k+1,0);
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(k+1,0);
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                {
                    curr[j]=1;
                    continue;
                }
                
                int cnt=0;
                for(int ind=0;ind<=min(i-1,j);ind++)
                cnt=(cnt+pre[j-ind])%mod;
                
                curr[j]=cnt;
            }
            pre=curr;
        }
        return pre[k];
    }
};