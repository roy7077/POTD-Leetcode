// Memoization
int mod=1e9+7;
#define ll long long
class Solution {
    public:
    int help(int n,int absent,int late,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(absent>=2 or late>=3)
        return 0;
        
        if(n==0)
        return 1;
        
        // memo check
        if(memo[n][absent][late]!=-1)
        return memo[n][absent][late];
        
        //recursive calls
        //and small calculation
        ll a=help(n-1,absent,0,memo);
        ll b=help(n-1,absent+1,0,memo);
        ll c=help(n-1,absent,late+1,memo);
        return memo[n][absent][late]=((a+b)%mod+c)%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        return help(n,0,0,memo);
    }
};



// Tabulation
int mod=1e9+7;
#define ll long long
class Solution {
    public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(4,0)));
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(j<2 and k<3)
                dp[0][j][k]=1;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(j>=2 or k>=3)
                    continue;
                    
                    ll a=dp[i-1][j][0];
                    ll b=dp[i-1][j+1][0];
                    ll c=dp[i-1][j][k+1];
                    dp[i][j][k]=((a+b)%mod+c)%mod;
                }
            }
        }
        return dp[n][0][0];
    }
};



// space optimized
int mod=1e9+7;
#define ll long long
class Solution {
    public:
    int checkRecord(int n) {
        vector<vector<int>> pre(3,vector<int>(4,0));
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(j<2 and k<3)
                pre[j][k]=1;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            vector<vector<int>> curr(3,vector<int>(4,0));
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(j>=2 or k>=3)
                    continue;
                    
                    ll a=pre[j][0];
                    ll b=pre[j+1][0];
                    ll c=pre[j][k+1];
                    curr[j][k]=((a+b)%mod+c)%mod;
                }
            }
            pre=curr;
        }
        return pre[0][0];
    }
};