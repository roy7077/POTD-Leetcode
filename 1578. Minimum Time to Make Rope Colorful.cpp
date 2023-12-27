// RECURSION
class Solution {
    public:
    int help(string& s,vector<int>& cost,int i,int last)
    {
        //base case
        if(i>=s.length())
        return 0;
        
        //recursive calls
        //small calculation
        char temp=s[i];
        s[i]='1';
        int a=cost[i]+help(s,cost,i+1,last);
        s[i]=temp;
        
        int b=1e9;
        if(last==-1 or s[last]!=s[i] or i==0)
        b=help(s,cost,i+1,i);
        
        return min(a,b);
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        int ans=help(colors,neededTime,0,-1);
        return ans;
    }
};


// MEMOIZATION
class Solution {
public:
    int helper(string &s, vector<int>& need,int index,int prev, vector<vector<int>> &dp){
        if(index==s.size()) return 0;
        if(dp[index][prev+1]!=-2) return dp[index][prev+1];
        int cost=need[index]+helper(s,need,index+1,prev,dp);
        if(prev!=(s[index]-'a')){
            cost=min(cost,helper(s,need,index+1,s[index]-'a',dp));
        }
        return dp[index][prev+1]= cost;
        
    }
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> dp(colors.size(),vector<int>(26,-2));
        return helper(colors,neededTime,0,-1,dp);    
    }   
};

// TABULATION
class Solution {
    public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>>dp(n+1, vector<int>(27, 0));
        
        for(int i = 0;i<=26;i++) {
            if(colors[0] - 'a' == i) dp[0][i] = neededTime[0];
            else dp[0][i] = 0;
        }
        
        for(int i = 1;i<n;i++) 
        {
            for(int j = 0;j<27;j++) 
            {
                int remove = 1e8;
                int notRemove = 1e8;
                remove = neededTime[i] + dp[i-1][j];
                
                if(colors[i] - 'a' != j) 
                notRemove = dp[i-1][colors[i] - 'a'];
                
                dp[i][j] = min(remove, notRemove);
            }
        }
        
        return dp[n-1][26];
    }   
};

// SPACE OPTIMIZED
class Solution {
    public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> pre(27,0);
        
        for(int i = 0;i<=26;i++) 
        {
            if(colors[0] - 'a' == i) 
            pre[i] = neededTime[0];
            else 
            pre[i] = 0;
        }
        
        for(int i = 1;i<n;i++) 
        {
            vector<int> curr(27,0);
            for(int j = 0;j<27;j++) 
            {
                int remove = 1e8;
                int notRemove = 1e8;
                remove = neededTime[i] + pre[j];
                
                if(colors[i] - 'a' != j) 
                notRemove = pre[colors[i] - 'a'];
                
                curr[j] = min(remove, notRemove);
            }
            pre=curr;
        }
        
        return pre[26];
    }   
};