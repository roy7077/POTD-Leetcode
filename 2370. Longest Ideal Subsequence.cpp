// Memoization - Optimization
class Solution {
    public:
    int help(string& s,int i,char preCh,int& k,vector<vector<int>>& memo)
    {
        //base case
        if(i>=s.length())
        return 0;
        
        //memo check
        if(preCh!='#' and memo[i][int(preCh)-97]!=-1)
        return memo[i][int(preCh)-97];
        
        //recursive calls
        //and small calculation
        int a=help(s,i+1,preCh,k,memo);
        int b=0;
        if(preCh=='#' or abs(preCh-s[i])<=k)
        b=1+help(s,i+1,s[i],k,memo);
        
        if(preCh=='#')
        return max(a,b);
        
        return memo[i][int(preCh)-97]=max(a,b);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> memo(s.length(),vector<int>(27,-1));
        return help(s,0,'#',k,memo);
    }
};