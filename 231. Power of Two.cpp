/* Method - 1
   bit
   Time complexity - O(1)
   Space complexity- O(1)
*/
class Solution {
    public:
    bool isPowerOfTwo(long long n) {
        if(n<=0)
        return 0;
        
        if(n!=1 and n&(n-1))
        return 0;
        else
        return 1;
    }
};

/* Method - 2
   while loop
   Time complexity - O(logN)
   Space complexity- O(1)
*/
class Solution {
    public:
    bool isPowerOfTwo(long long n) {
        if(n<0)
        return 0;
        
        long long pw=1;
        while(pw<=n)
        {
            if(pw==n)
            return 1;
            
            pw*=2;
        }
        return 0;
    }
};