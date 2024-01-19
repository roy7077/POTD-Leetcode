//RECURSION
function help(matrix,i,j,n)
{
    //base case
    if(i==n-1)
    {
        console.log(matrix[i][j]);
        return matrix[i][j];
    }
    
    //recursive calls
    //small calculation
    let a,b,c;
    a=b=c=1e9;
    
    //below
    if((i+1)<n)
    a=matrix[i][j]+help(matrix,i+1,j,n);
    
    //right diagonal
    if((i+1)<n && (j+1)<n)
    b=matrix[i][j]+help(matrix,i+1,j+1,n);
    
    //left diagonal
    if((i+1)<n && (j-1)>=0)
    c=matrix[i][j]+help(matrix,i+1,j-1,n);
    
    return Math.min(a,b,c);
}
var minFallingPathSum = function(matrix) {
    let n=matrix.length;
    let ans=1e9;
    
    for(let i=0;i<n;i++)
    {
        let temp=help(matrix,0,i,n);
        ans=Math.min(ans,temp);
    }
    return ans;
};


//MEMOIZATION
function help(matrix,i,j,n,memo)
{
    //base case
    if(i==n-1)
    {
        console.log(matrix[i][j]);
        return matrix[i][j];
    }
    
    //memo check
    if(memo[i][j]>-1e9)
    return memo[i][j];
    
    //recursive calls
    //small calculation
    let a,b,c;
    a=b=c=1e9;
    
    //below
    if((i+1)<n)
    a=matrix[i][j]+help(matrix,i+1,j,n,memo);
    
    //right diagonal
    if((i+1)<n && (j+1)<n)
    b=matrix[i][j]+help(matrix,i+1,j+1,n,memo);
    
    //left diagonal
    if((i+1)<n && (j-1)>=0)
    c=matrix[i][j]+help(matrix,i+1,j-1,n,memo);
    
    return memo[i][j]=Math.min(a,b,c);
}
var minFallingPathSum = function(matrix) {
    let n=matrix.length;
    let ans=1e9;
    
    //making 2D memo vector
    let memo=new Array(n);
    for(let i=0;i<n;i++)
    {
        memo[i]=[];
        for(let j=0;j<n;j++)
        memo[i][j]=-1e9;
    }
    
    for(let i=0;i<n;i++)
    {
        let temp=help(matrix,0,i,n,memo);
        ans=Math.min(ans,temp);
    }
    return ans;
};


//TABULATION
var minFallingPathSum = function(matrix) {
    let n=matrix.length;
    let ans=1e9;
    
    //making 2D memo vector
    let dp=new Array(n);
    for(let i=0;i<n;i++)
    {
        dp[i]=[];
        for(let j=0;j<n;j++)
        dp[i][j]=-1e9;
    }
    
    for(let i=0;i<n;i++)
    dp[n-1][i]=matrix[n-1][i];
    
    for(let i=n-2;i>=0;i--)
    {
        for(let j=0;j<n;j++)
        {
            let a,b,c;
            a=b=c=1e9;
            
            a=matrix[i][j]+dp[i+1][j];
            
            if(j+1<n)
            b=matrix[i][j]+dp[i+1][j+1];
            
            if(j-1>=0)
            c=matrix[i][j]+dp[i+1][j-1];
            
            dp[i][j]=Math.min(a,b,c);
        }
    }
    
    for(let i=0;i<n;i++)
    ans=Math.min(ans,dp[0][i]);
    
    return ans <=-1e9? -1:ans;
};


//SPACE OPTIMIZED
var minFallingPathSum = function(matrix) {
    let n=matrix.length;
    let ans=1e9;
    
    //making 2D memo vector
    let next=new Array(n);

    for(let i=0;i<n;i++)
    next[i]=matrix[n-1][i];
    
    for(let i=n-2;i>=0;i--)
    {
        let curr=new Array(n);
        for(let j=0;j<n;j++)
        {
            let a,b,c;
            a=b=c=1e9;
            
            a=matrix[i][j]+next[j];
            
            if(j+1<n)
            b=matrix[i][j]+next[j+1];
            
            if(j-1>=0)
            c=matrix[i][j]+next[j-1];
            
            curr[j]=Math.min(a,b,c);
        }
        next=curr;
        delete curr;
    }
    
    for(let i=0;i<n;i++)
    ans=Math.min(ans,next[i]);
    
    return ans <=-1e9? -1:ans;
};