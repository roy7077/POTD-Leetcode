// Method - 1
// Time complexity - O(N^2)
// Space complexity- O(N)
class Solution {
    public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int maxi=101;
        tickets[k]=(4*maxi)+tickets[k];
        
        queue<int> q;
        for(auto it:tickets)
        q.push(it);
        
        int cntTime=0;
        while(!q.empty())
        {
            int num=q.front();
            q.pop();
            
            cntTime++;
            if((num/maxi)==4)
            {
                int orig=num%maxi;
                if(orig==1)
                return cntTime;
                
                orig--;
                q.push((4*maxi)+orig);
                continue;
            }
            
            if(num!=1)
            q.push(--num);
        }
        return cntTime;
    }
};


// Method - 2
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cntTime=0;
        for(int i=0;i<tickets.size();i++)
        {
            if(i<=k)
            cntTime+=min(tickets[i],tickets[k]);
            else
            cntTime+=min(tickets[i],tickets[k]-1);
        }
        return cntTime;
    }
};