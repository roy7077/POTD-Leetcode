
// Time complexity - O(32)
// Space complexity- O(1)
class Solution {
    public:
    int minBitFlips(int start, int goal) {
        
        int flipBit=0;
        for(int i=0;i<32;i++)
        {
            if((start&(1<<i)) and (goal&(1<<i)))
            continue;
            else if((start&(1<<i))==0 and (goal&(1<<i))==0)
            continue;
                    
            flipBit++;
        }
        return flipBit;
    }
};
