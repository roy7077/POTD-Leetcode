// Memoization
class Solution {
    public:
    bool flag=0;
    vector<int> v;
    void squares()
    {
        int i=1;
        while(1)
        {
            if((i*i)<=1e5)
            v.push_back(i*i);
            else 
            break;
            i++;
        }
        flag=1;
    }
    
    int help(int n,int i,int size,vector<vector<int>>& memo)
    {
        //base case
        if(n==0)
        return 0;
        
        if(n<0)
        return 1e9;
        
        if(i>size)
        {
            if(n==0)
            return 0;
            else
            return 1e9;
        }
        
        //memo check
        if(memo[n][i]!=-1)
        return memo[n][i];
        
        //recursive calls
        //and small calculation
        int a=help(n,i+1,size,memo);
        int b=1+help(n-v[i],i,size,memo);
        
        return memo[n][i]=min(a,b);
    }
    int numSquares(int n) {
        if(!flag)
        squares();
        
        vector<vector<int>> memo(n+1,vector<int>(sqrt(n)+2,-1));
        int ind=sqrt(n);
        int ans=help(n,0,ind,memo);
        return ans;
    }
};

// Tabulation
class Solution {
    public:
    bool flag=0;
    vector<int> v;
    void squares()
    {
        int i=1;
        while(1)
        {
            if((i*i)<=1e5)
            v.push_back(i*i);
            else 
            break;
            i++;
        }
        flag=1;
    }
    
    int numSquares(int n) {
        if(!flag)
        squares();
        
        int ind=sqrt(n);
        vector<vector<int>> dp(ind,vector<int>(n+2,0));
        
        for(int i=0;i<ind;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int a,b;
                a=b=1e9;
                
                if(i-1>=0)
                a=dp[i-1][j];
                
                if(j-v[i]>=0)
                b=1+dp[i][j-v[i]];
                
                dp[i][j]=min(a,b);
            }
        }
        return dp[ind-1][n];
     }
};

// Space optimized
class Solution {
    public:
    bool flag=0;
    vector<int> v;
    void squares()
    {
        int i=1;
        while(1)
        {
            if((i*i)<=1e5)
            v.push_back(i*i);
            else 
            break;
            i++;
        }
        flag=1;
    }
    
    int numSquares(int n) {
        if(!flag)
        squares();
        
        int ind=sqrt(n);
        vector<int> pre(n+2,0);
        
        for(int i=0;i<ind;i++)
        {
            vector<int> curr=pre;
            for(int j=1;j<=n;j++)
            {
                int a,b;
                a=b=1e9;
                
                if(i-1>=0)
                a=pre[j];
                
                if(j-v[i]>=0)
                b=1+curr[j-v[i]];
                
                curr[j]=min(a,b);
            }
            pre=curr;
        }
        return pre[n];
     }
};