#define ll long long
int mod=1e9+7;
class Solution {
    public:
    ll help(int len,int steps,int i,vector<vector<ll>>& memo)
    {
        //base case
        if(steps==0)
        return i==0 ? 1:0;
        
        if(i<0 or i>=len or i>steps)			
        return 0;
        
        //memo check
        if(memo[i][steps]!=-1)
        return memo[i][steps];
        
        //recursive calls
        //small calculation
        ll a=help(len,steps-1,i,memo);
        ll b=help(len,steps-1,i-1,memo);
        ll c=help(len,steps-1,i+1,memo);
        
        return memo[i][steps]=((a+b)%mod+c)%mod;
    }
    
    int numWays(int steps, int arrLen) {
        
        vector<vector<ll>> memo(steps/2+1,vector<ll>(steps+1,-1));
        return help(arrLen,steps,0,memo);
        /*--------Tabulation -------
        int mini=min(steps,arrLen);
        vector<ll> pre(mini,0);
        pre[0]=1;
        for(int i=1;i<=steps;i++)
        {
            vector<ll> curr(arrLen,0);
            for(int j=0;j<mini;j++)
            {
                ll a,b,c;
                a=b=c=0;
                
                a=pre[j];
                
                if(j-1>=0)
                b=pre[j-1];
                
                if(j+1<mini)
                c=pre[j+1];
                
                curr[j]=(((a+b)%mod)+c)%mod;
            }
            pre=curr;
        }
        
        return pre[0];
        */
    }
};