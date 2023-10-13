
// Recursion
class Solution {
public:
    
    int help(vector<int>& cost,int i)
    {
        //base case
        if(i>=cost.size())
        return 0;
        
        //recursive calls
        //small calculation
        
        int c=1e9;
        if(i==0)
        c=help(cost,i+1);
            
        int a,b;
        a=b=1e9;
        a=cost[i]+help(cost,i+1);
        b=cost[i]+help(cost,i+2);

        return min({a,b,c});
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int ans1=help(cost,0);
        return ans1>=1e9 ? -1:ans1;
    }
};


// Memoization
class Solution {
public:
    
    int help(vector<int>& cost,int i,vector<int>& memo)
    {
        //base case
        if(i>=cost.size())
        return 0;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        //small calculation
        
        int c=1e9;
        if(i==0)
        c=help(cost,i+1,memo);
            
        int a,b;
        a=b=1e9;
        a=cost[i]+help(cost,i+1,memo);
        b=cost[i]+help(cost,i+2,memo);

        return memo[i]=min({a,b,c});
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> memo(cost.size()+1,-1);
        int ans1=help(cost,0,memo);
        
        return ans1>=1e9 ? -1:ans1;
    }
};


// Tabulation
class Solution {
    public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size(),0);
        int n=cost.size();
        dp[n-1]=cost[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            int a,b,c;
            c=1e9;
            a=b=cost[i];
            
            if(i==0)
            c=dp[i+1];
            
            a+=dp[i+1];
            if(i+2<n)
            b+=dp[i+2];
            
            dp[i]=min({a,b,c});
        }
        
        return dp[0];
    }
};

// Space optimized
class Solution {
    public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int next=cost[n-1];
        int secondnext;
        
        for(int i=n-2;i>=0;i--)
        {
            int a,b,c;
            c=1e9;
            a=b=cost[i];
            
            if(i==0)
            c=next;
            
            a+=next;
            if(i+2<n)
            b+=secondnext;
            
            int curr=min({a,b,c});
            secondnext=next;
            next=curr;
        }
        
        return next;
    }
};
