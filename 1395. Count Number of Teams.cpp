
// Method - 1
// Memoization
class Solution {
    public:
    int help1(vector<int>& rating,int i,int pre,int cnt,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(i>=rating.size())
        return cnt==0;
        
        if(cnt==0)
        return 1;
        
        // memo check
        if(memo[i][pre+1][cnt]!=-1)
        return memo[i][pre+1][cnt];
        
        //recursive calls & small calculation
        int a=help1(rating,i+1,pre,cnt,memo);
        int b=0;
        if(pre==-1)
        b=help1(rating,i+1,i,cnt-1,memo);
        else if(rating[i]>rating[pre])
        b=help1(rating,i+1,i,cnt-1,memo);
        
        return memo[i][pre+1][cnt]=(a+b);
    }
    int help2(vector<int>& rating,int i,int pre,int cnt,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(i>=rating.size())
        return cnt==0;
        
        if(cnt==0)
        return 1;
        
        // memo check
        if(memo[i][pre+1][cnt]!=-1)
        return memo[i][pre+1][cnt];
        
        //recursive calls & small calculation
        int a=help2(rating,i+1,pre,cnt,memo);
        int b=0;
        if(pre==-1)
        b=help2(rating,i+1,i,cnt-1,memo);
        else if(rating[i]<rating[pre])
        b=help2(rating,i+1,i,cnt-1,memo);
        
        return memo[i][pre+1][cnt]=(a+b);
    }
    int numTeams(vector<int>& rating) {
        
        int n=rating.size();
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(n+1,vector<int>(4,-1)));
        int a=help1(rating,0,-1,3,memo);
        memo.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(4, -1)));
        int b=help2(rating,0,-1,3,memo);
        
        return (a+b);
    }
};


// [4,7,9,5,10,8,2,1,6]



// Method - 2
// Tabulation
class Solution {
    public:
    int help1(vector<int>& rating,vector<vector<vector<int>>>& dp,int flag)
    {
        int n=rating.size();
        for(int j=0;j<=n;j++)
        dp[n][j][0]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=3;k++)
                {
                    if(k==0)
                    {
                        dp[i][j][k]=1;
                        continue;
                    }
                    
                    int a=dp[i+1][j][k];
                    int b=0;
                    if(j==0)
                    b=dp[i+1][i+1][k-1];
                    else
                    {
                        if(flag and rating[i]>rating[j-1])
                        b=dp[i+1][i+1][k-1];
                        else if(!flag and rating[i]<rating[j-1])
                        b=dp[i+1][i+1][k-1];
                    }
                    dp[i][j][k]=(a+b);
                }
            }
        }
        return dp[0][0][3];
    }
    
    int numTeams(vector<int>& rating) {
        
        int n=rating.size();
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(n+1,vector<int>(4,0)));
        int a=help1(rating,memo,1);
        
        memo.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(4, 0)));
        int b=help1(rating,memo,0);
        
        return (a+b);
    }
};


// [4,7,9,5,10,8,2,1,6]
