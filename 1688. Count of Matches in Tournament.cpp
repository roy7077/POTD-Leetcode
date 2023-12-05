// Time complexity - O(log(N))
// Space complexity- O(1
class Solution {
    public:
    int numberOfMatches(int n) {
        
        int cnt=0;
        while(n>1)
        {
            if(n&1)
            {
                n=(n-1)/2;
                cnt+=n;
                n++;
            }
            else
            {
                n/=2;
                cnt+=n;
            }
        }
        return cnt;
    }
};