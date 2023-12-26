// RECURSION
class Solution {
    public:
    int help(int n,int k,int i,int target)
    {
        //base case
        if(i>n)
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        
        if(target==0)
        return 1;
        
        //recursive calls
        //small calculation
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if(target>=j)
            ans+=help(n,k,i+1,target-j);
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        int ans=help(n,k,1,target);
        return ans;
    }
};


// MEMOIZATION
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    ll help(int n,int k,int target,vector<vector<ll>>& memo)
    {
        //base case
        if(n<=0)
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        
        //memo check
        if(memo[n][target]!=-1)
        return memo[n][target];
        
        //recursive calls
        //small calculation
        ll ans=0;
        for(int j=1;j<=k;j++)
        {
            if(target>=j)
            ans=(ans+help(n-1,k,target-j,memo))%mod;
        }
        return memo[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> memo(n+1,vector<ll>(target+1,-1));
        ll ans=help(n,k,target,memo)%mod;
        return ans;
    }
};

// TABULATION
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n+1,vector<ll>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int ans=0;
                for(int l=1;l<=k;l++)
                {
                    if(j-l>=0)
                    ans=(ans+dp[i-1][j-l])%mod;
                }
                dp[i][j]=ans;
            }
        }
        
        return dp[n][target];
    }
};

// SPACE OPTIMIZED
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int numRollsToTarget(int n, int k, int target) {
        vector<ll> pre(target+1,0);
        pre[0]=1;
        for(int i=1;i<=n;i++)
        {
            vector<ll> curr(target+1,0);
            for(int j=1;j<=target;j++)
            {
                int ans=0;
                for(int l=1;l<=k;l++)
                {
                    if(j-l>=0)
                    ans=(ans+pre[j-l])%mod;
                }
                curr[j]=ans;
            }
            pre=curr;
        }
        return pre[target];
    }
};