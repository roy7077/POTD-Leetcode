// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long waitingTime=0;
        int chef=0;
        
        for(int i=0;i<customers.size();i++)
        {
            int t1=0;
            if(chef<customers[i][0])
            {
                t1=customers[i][1];
                chef=customers[i][0]+customers[i][1];
            }
            else
            {
                t1=chef-customers[i][0]+customers[i][1];
                chef+=customers[i][1];
            }
            
            waitingTime+=t1;
        }
        
        return (double)waitingTime/customers.size();
    }
};
