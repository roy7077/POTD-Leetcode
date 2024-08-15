
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;
        
        for(auto& it:bills)
        {
            if(it==5)
            five++;
            else if(it==10)
            {
                if(five==0)
                return 0;
                else
                {
                    five--;
                    ten++;
                }
            }
            else
            {
                if(ten>=1 and five>=1)
                {
                    ten--;
                    five--;
                    twenty++;
                }
                else if(five>=3)
                {
                    five-=3;
                    twenty++;
                }
                else
                return 0;
            }
        }
        return 1;
    }
};
