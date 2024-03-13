
// Method - 1
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int pivotInteger(int n) {
        int sum=(n*(n+1))/2.0;
        int sum2=0;
        for(int i=1;i<=n;i++)
        {
            sum2+=i;
            if(sum2==(sum-sum2+i))
            return i;
        }
        return -1;
    }
};


// Method - 2
// Prefix and suffix sum
// Time complexity - O(N)
// Space complexity- O(N+)
class Solution {
    public:
    int pivotInteger(int n) {
        vector<int> pre(n+2,0);
        vector<int> suf(n+2,0);
        
        //prefix
        for(int i=1;i<=n;i++)
        pre[i]=i+pre[i-1];
        
        //sufix
        for(int i=n;i>=1;i--)
        suf[i]=i+suf[i+1];
        
        for(int i=1;i<=n;i++)
        {
            if(pre[i]==suf[i])
            return i;
        }
        
        return -1;
    }
};