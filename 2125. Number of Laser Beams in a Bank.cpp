// Time complexity - O(N*size of string)
// Space complexity- O(1)
class Solution {
    public:
    int numberOfBeams(vector<string>& bank) {
        int next=0;
        int sum=0;
        bool flag=0;
        
        int n=bank.size();
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            for(auto it:bank[i])
            {
                if(it=='1')
                cnt++;
            }
            
            if(!flag)
            ans+=cnt*(next+sum);
            else
            ans+=cnt*next;
            
            if(cnt)
            {
                flag=1;
                next=cnt;
                sum=0;
            }
            else
            flag=0;
            
        }
        return ans;
    }
};

// ans[n-1]=0;
// ans[n-2]=2;
// ans[n-3]=0;
// ans[n-4]=8