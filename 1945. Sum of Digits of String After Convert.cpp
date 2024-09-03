// Time complexity - O(N+18*18)
// Space complexity- O(1)
class Solution {
    public:
    int getLucky(string s, int k) {
        
        // step - 1
        int sum=0;
        for(auto& it:s)
        {
            int pos=it-'a'+1;
            while(pos)
            {
                sum+=pos%10;
                pos/=10;
            }
        }
        
        k--;
        // step - 2
        while(k--)
        {
            int tempSum=0;
            while(sum)
            {
                tempSum+=sum%10;
                sum/=10;
            }
            sum=tempSum;
        }
        
        return sum;
    }
};


