// Time complexity - O(M*NlogN)
// Space complexity- O(N)
class Solution {
    public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        
        vector<bool> ans;
        int n=nums.size();
        int m=l.size();
        
        for(int i=0;i<m;i++)
        {
            int s=l[i];
            int e=r[i];
            
            //if range consist less than 1 element
            if((e-s)<=1)
            {
                ans.push_back(1);
                continue;
            }
            
            priority_queue<int> pq;
            int pre;
            
            for(int j=s;j<=e;j++)
            pq.push(nums[j]);
            
            
            pre=pq.top();
            pq.pop();
            
            int d=0;
            bool flag=1;
            bool done=1;
            while(!pq.empty())
            {
                int f=pq.top();
                pq.pop();
                
                int diff=pre-f;
                pre=f;
                if(flag)
                {
                    d=diff;
                    flag=0;
                }
                else
                {
                    if(diff!=d)
                    {
                        ans.push_back(0);
                        done=0;
                        break;
                    }
                }
            }
            
            if(done)
            ans.push_back(1);
            
        }
        return ans;
    }
};