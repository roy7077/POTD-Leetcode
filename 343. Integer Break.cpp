// MEMOIZATION

#define ll long long
class Solution {
    public:
    ll help(ll n,vector<ll>& memo)
    {
        //base case
        if(n<=2)
        return 1;
        
        if(n<0)
        return 0;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls
        //small calculation
        
        ll ans=0;
        for(int i=0;i<=n;i++)
        {
            ll temp1=i*help(n-i,memo);
            ll temp2=i*(n-i);
            ans=max({ans,temp1,temp2});
        }
        
        return memo[n]=ans;
    }
    
    int integerBreak(int n) {
    
       vector<ll> v(n+1,-1);
       return help(n,v);

    }
};

// TABULATION

#define ll long long
class Solution {
    public:
    int integerBreak(int n) {
    
        if(n<=2)
        return 1;
        
        vector<ll> dp(n+1,0);
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            ll maxi=0;
            for(int j=0;j<=i;j++)
            {
                ll ans1=j*dp[i-j];
                ll ans2=j*(i-j);
                maxi=max({ans1,ans2,maxi});
            }
            dp[i]=maxi;
        }
        
        return dp[n];
        
    }
};