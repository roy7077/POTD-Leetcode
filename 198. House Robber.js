//RECURSION 
function help(nums,i)
{
    //base case
    if(i==0)
    return nums[0];
    
    if(i<0)
    return 0;
    //recursive calls
    //small calculation
    let a,b;
    a=b=0;
    
    a=help(nums,i-1);
    b=nums[i]+help(nums,i-2);
    
    return Math.max(a,b);
}

var rob = function(nums) {
    let ans=help(nums,nums.length-1);
    return ans;
};


//MEMOIZATION 
function help(nums,i,memo)
{
    //base case
    if(i==0)
    return nums[0];
    
    if(i<0)
    return 0;
    
    //memo check
    if(memo[i]!=-1)
    return memo[i];
    
    //recursive calls
    //small calculation
    let a,b;
    a=b=0;
    
    a=help(nums,i-1,memo);
    b=nums[i]+help(nums,i-2,memo);
    
    return memo[i]=Math.max(a,b);
}

var rob = function(nums) {
    
    let memo=new Array(nums.length).fill(-1);
    let ans=help(nums,nums.length-1,memo);
    return ans;
};


//TABULATION 
var rob = function(nums) {
    
    let dp=new Array(nums.length).fill(0);
    for(let i=0;i<nums.length;i++)
    {
        let a,b;
        a=b=0;
        
        if(i-1>=0)
        a=dp[i-1];
        
        b=nums[i];
        if(i-2>=0)
        b+=dp[i-2];
        
        dp[i]=Math.max(a,b);
    }
    return dp[nums.length-1];
};

//SPACE OPTIMIZED
var rob = function(nums) {
    
    let pre,pre2;
    pre=pre2=0;
    for(let i=0;i<nums.length;i++)
    {
        let a,b;
        a=b=0;
        
        if(i-1>=0)
        a=pre;
        
        b=nums[i];
        if(i-2>=0)
        b+=pre2;
        
        let curr=Math.max(a,b);
        pre2=pre;
        pre=curr;
    }
    return pre;
};