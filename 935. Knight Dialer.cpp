#define ll long long
int  mod=1e9+7;
class Solution {
    public:
    int help(ll i,ll j,ll n,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(i < 0 or j < 0 or i >= 4 or j >= 3 or (i == 3 && j != 1)) 
        return 0;
            
        if(n==1)
        return 1;
        
        //memo check
        if(memo[n][i][j]!=-1)
        return memo[n][i][j];
        
        //recursive calls & small calculation
        ll a=help (i - 1, j - 2,n-1,memo)%mod;
        ll b=help (i - 2, j - 1,n-1,memo)%mod;
        ll c=help (i - 2, j + 1,n-1,memo)%mod;
        ll d=help (i - 1, j + 2,n-1,memo)%mod;
        ll e=help (i + 1, j + 2,n-1,memo)%mod;
        ll f=help (i + 2, j + 1,n-1,memo)%mod;
        ll g=help (i + 2, j - 1,n-1,memo)%mod;
        ll h=help (i + 1, j - 2,n-1,memo)%mod;
        
        return memo[n][i][j]= (((((((((((((a+b)%mod)+c)%mod)+d)%mod)+e)%mod)+f)+mod)+g)%mod)+h)%mod;
    }
    
    int knightDialer(int n) {
        ll ans=0;
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(5,vector<int>(5,-1)));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            ans=(ans+help(i,j,n,memo))%mod;
        }
        
        return ans;

    }
};
