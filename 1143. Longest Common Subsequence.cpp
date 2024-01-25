// Recursion
class Solution {
    public:
    int help(string& s1,string& s2,int i,int j)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //recursive calls
        //small calculation
        
        if(s1[i]==s2[j])
        return 1+help(s1,s2,i-1,j-1);
        
        int a=help(s1,s2,i-1,j);
        int b=help(s1,s2,i,j-1);
        
        return max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        return help(text1,text2,text1.length()-1,text2.length()-1);
    }
};


// Memoization
class Solution {
    public:
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //small calculation
        
        if(s1[i]==s2[j])
        return 1+help(s1,s2,i-1,j-1,memo);
        
        int a=help(s1,s2,i-1,j,memo);
        int b=help(s1,s2,i,j-1,memo);
        
        return memo[i][j]=max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length(),vector<int>(text2.length(),-1));
        return help(text1,text2,text1.length()-1,text2.length()-1,memo);
    }
};


// Tabulation
class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=1;i<=text1.length();i++)
        {
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                
                dp[i][j]=max(a,b);
            }
        }
        
        return dp[text1.length()][text2.length()];
    }
};


// Space optimized
class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> pre(text2.length()+1,0);
        for(int i=1;i<=text1.length();i++)
        {
            vector<int> curr(text2.length()+1,0);
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j]=1+pre[j-1];
                    continue;
                }
                
                int a=pre[j];
                int b=curr[j-1];
                
                curr[j]=max(a,b);
            }
            pre=curr;
        }
        
        return pre[text2.length()];
    }
};