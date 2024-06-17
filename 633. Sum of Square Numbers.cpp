// Time complexity - O(sqrt(N))
// Space complexity- O(1)
class Solution {
    public:
    bool isSquare(int n,int c)
    {
        int n1=n*n;
        int n2=c-n1;
        
        int temp=sqrt(n2);
        if((temp*temp)!=n2)
        return 0;
        
        return 1;
    }
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++)
        {
            if(isSquare(i,c))
            return 1;
        }
        return 0;
    }
};