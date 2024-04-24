// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int tribonacci(int n) {
        int a=0;
        int b=1;
        int c=1;
        
        //base cases
        if(n==0)
        return 0;
        
        if(n==1)
        return 1;
        
        //calculation of Nth Tribonacci number
        for(int i=3;i<=n;i++)
        {
            int curr=a+b+c;
            a=b;
            b=c;
            c=curr;
        }
        return c;
    }
};