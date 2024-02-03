
// MEMOIZATION
class Solution {
    public:
    int help(vector<int>& arr,int i,int& k,vector<int>& memo)
    {
        //base case
        if(i>=arr.size())
        return 0;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        //and small calculation
        int m=-1e9;
        int ans=-1;
        for(int j=i;j<(i+k) and j<arr.size();j++)
        {
            m=max(m,arr[j]);
            int temp=((j-i+1)*m)+help(arr,j+1,k,memo);
            ans=max(ans,temp);
        }
        return memo[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> memo(arr.size(),-1);
        
        int ans=help(arr,0,k,memo);
        return ans;
    }
};

// TABULATION
class Solution {
    public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--)
        {
            int m=-1e9;
            int ans=-1;
            for(int j=i;j<(i+k) and j<arr.size();j++)
            {
                m=max(m,arr[j]);
                int temp=((j-i+1)*m);
                if((j+1)<arr.size())
                temp+=dp[j+1];
                
                ans=max(ans,temp);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};

// SPACE OPTIMIZED
class Solution {
    public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int m=-1e9;
            int ans=-1;
            for(int j=i;j<(i+k) and j<arr.size();j++)
            {
                m=max(m,arr[j]);
                int temp=((j-i+1)*m);
                if((j+1)<arr.size())
                temp+=dp[j-i];
                
                ans=max(ans,temp);
            }
            dp.insert(dp.begin(),ans);
            if(dp.size()>k)
            dp.pop_back();
        }
        return dp[0];
    }
};