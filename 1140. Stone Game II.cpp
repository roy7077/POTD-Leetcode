
// memoization
class Solution {
    public:
    int help(vector<int>& piles,int i,int m,int turn,vector<vector<vector<int>>>& memo)
    {
        // base case
        if(i>=piles.size())
        return 0;
        
        // memo check
        if(memo[i][m][turn]!=-1)
        return memo[i][m][turn];
        
        // recursive calls
        // and small calculation
        if(turn)
        {
            int maxSum=0;
            int sum=0;
            for(int j=i;j<(i+2*m);j++)
            {
                if(j>=piles.size())
                break;
                
                sum+=piles[j];
                int newM=max(m,j-i+1);
                int fnCall=sum+help(piles,j+1,newM,0,memo);
                maxSum=max(maxSum,fnCall);
            }
            return memo[i][m][turn]=maxSum;
        }
        else
        {
            int minSum=1e9;
            int sum=0;
            for(int j=i;j<(i+2*m);j++)
            {
                if(j>=piles.size())
                break;
                
                sum+=piles[j];
                int newM=max(m,j-i+1);
                int fnCall=help(piles,j+1,newM,1,memo);
                minSum=min(minSum,fnCall);
            }
            return memo[i][m][turn]=minSum;
        }
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(2*n+1,vector<int>(2,-1)));
        return help(piles,0,1,1,memo);
    }
};

// 100*200*2
// 0 1 2 3 4 5 6
