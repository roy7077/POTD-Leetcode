// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
            sum+=customers[i];
        }
        
        int i=0;
        while(i<minutes)
        {
            if(grumpy[i]==1)
            sum+=customers[i];
            
            i++;
        }
        
        int maxi=sum;
        int j=0;
        while(i<customers.size())
        {
            if(grumpy[j]==1)
            sum-=customers[j];
            
            if(grumpy[i]==1)
            sum+=customers[i];
            
            maxi=max(maxi,sum);
            i++;
            j++;
        }
        return maxi;
    }
};