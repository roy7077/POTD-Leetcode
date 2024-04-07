// Simple Recursion - 3^n (TLE for sure)
class Solution {
    public:
    bool help(string& s,int i,int cnt)
    {
        //base case
        if(i>=s.length())
        return cnt==0;
        
        //recursive calls
        //and small calculation
        if(s[i]=='(')
        return help(s,i+1,cnt+1);
        
        if(s[i]==')')
        {
            if(cnt>0)
            return help(s,i+1,cnt-1);
            else
            return 0;
        }
        
        for(int k=-1;k<=1;k++)
        {
            if(cnt==0 and k==-1)
            continue;
            
            bool call=help(s,i+1,cnt+k);
            if(call)
            return 1;
        }
        
        return 0;
    }
    bool checkValidString(string s) {
        return help(s,0,0);
    }
};


// Memoization
class Solution {
    public:
    bool help(string& s,int i,int cnt,vector<vector<int>>& memo)
    {
        //base case
        if(i>=s.length())
        return cnt==0;
        
        //memo check
        if(memo[i][cnt]!=-1)
        return memo[i][cnt];
        
        //recursive calls
        //and small calculation
        if(s[i]=='(')
        return memo[i][cnt]=help(s,i+1,cnt+1,memo);
        
        if(s[i]==')')
        {
            if(cnt>0)
            return memo[i][cnt]=help(s,i+1,cnt-1,memo);
            else
            return 0;
        }
        
        bool ans=0;
        for(int k=-1;k<=1;k++)
        {
            if(cnt==0 and k==-1)
            continue;
            
            bool call=help(s,i+1,cnt+k,memo);
            if(call)
            {
                ans=1;
                break;
            }
        }
        
        return memo[i][cnt]=ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.length(),vector<int>(s.length(),-1));
        return help(s,0,0,memo);
    }
};


// Tabulation
// Time complexity - O(N*N)
// Space complexity- O(N*N)
class Solution {
    public:
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        dp[n][0]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                //if open bracket
                if(s[i]=='(')
                {
                    dp[i][j]=dp[i+1][j+1];
                    continue;
                }
                
                //if close bracket
                if(s[i]==')')
                {
                    if(j==0)
                    dp[i][j]=0;
                    else
                    dp[i][j]=dp[i+1][j-1];
                    
                    continue;
                }
                
                //if * is there , then there are 3 choices
                bool ans=0;
                for(int k=-1;k<=1;k++)
                {
                    if(j==0 and k==-1)
                    continue;

                    bool call=dp[i+1][j+k];
                    if(call)
                    {
                        ans=1;
                        break;
                    }
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};



// space optimized
// Time complexity - O(N*N)
// Space complexity- O(N)
class Solution {
    public:
    bool checkValidString(string s) {
        int n=s.length();
        vector<int> next(n+1,0);
        next[0]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(n+1,0);
            for(int j=0;j<n;j++)
            {
                //if open bracket
                if(s[i]=='(')
                {
                    curr[j]=next[j+1];
                    continue;
                }
                
                //if close bracket
                if(s[i]==')')
                {
                    if(j==0)
                    curr[j]=0;
                    else
                    curr[j]=next[j-1];
                    
                    continue;
                }
                
                //if * is there , then there are 3 choices
                bool ans=0;
                for(int k=-1;k<=1;k++)
                {
                    if(j==0 and k==-1)
                    continue;

                    bool call=next[j+k];
                    if(call)
                    {
                        ans=1;
                        break;
                    }
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
};
