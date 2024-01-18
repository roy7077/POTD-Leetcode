// RECURSION
function help(n)
{
    //base case
    if(n==0)
    return 1;
    
    if(n<0)
    return 0;
    
    //recursive calls
    //small calculation
    let a=help(n-1);
    let b=help(n-2);
    
    return (a+b);
}
var climbStairs = function(n) {
    let ans=help(n);
    return ans;
};


// MEMOIZATION
function help(n,memo)
{
    //base case
    if(n==0)
    return 1;
    
    if(n<0)
    return 0;
    
    //memo check
    if(memo[n]!=-1)
    return memo[n];
    
    //recursive calls
    //small calculation
    let a=help(n-1,memo);
    let b=help(n-2,memo);
    
    return memo[n]=(a+b);
}
var climbStairs = function(n) {
    
    let memo = new Array(n+1);
    for(let i=0;i<=n;i++)
    memo[i]=-1;
    
    let ans=help(n,memo);
    return ans;
};


// TABULATION
var climbStairs = function(n) {
    
    let dp = new Array(n+1);
    dp[0]=1;
    dp[1]=1;
    
    for(let i=2;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];
    
    return dp[n];
};


// SPACE OPTIMIZED
var climbStairs = function(n) {
   
    if(n==0 || n==1)
    return 1;
    
    let a=1;
    let b=1;
    
    for(let i=2;i<=n;i++)
    {
        let curr=a+b;
        a=b;
        b=curr;
    }
    
    return b;
};