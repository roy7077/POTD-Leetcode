//Time complexity - O(N)
//Space complexity- O(1)
class Solution {
    public:
    int totalMoney(int n) {
        
        int mul=0;
        int ans=0;
        while(n>=7)
        {
            ans+=(28+mul*7);
            n-=7;
            mul++;
        }
        
        if(n)
        {
            ans+=mul*n;
            for(int i=1;i<=n;i++)
            ans+=i;
        }
        
        return ans;
    }
};