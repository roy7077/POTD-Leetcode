// Method - 1
// Time complexity - O(31*N)
// Space complexity- O(1)
class Solution {
    public:
    int cntFlipBit(int a,int b)
    {
        int cntOp=0;
        for(int i=0;i<31;i++)
        {
            int bit1=(1<<i)&a;
            int bit2=(1<<i)&b;
            
            if(bit1!=bit2)
            cntOp++;
        }
        return cntOp;
    }
    int minOperations(vector<int>& nums, int k) {
        int xorr=0;
        for(auto& it:nums)
        xorr^=it;
        
        return cntFlipBit(xorr,k);
    }
};