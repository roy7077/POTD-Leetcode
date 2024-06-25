class Solution {
    public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n+2,0);
        
        int cnt=0;
        for(int i=0;i<=n-k;i++)
        {
            if(i==0)
            {
                if(nums[i]==0)
                {
                    v[i]=1;
                    v[i+k]+=-1;
                    cnt++;
                }
                nums[i]=1;
                continue;
            }
            
            // 0 1 2 3 4
                
            v[i]+=v[i-1];
            if(nums[i]==0)
            {
                if(v[i]%2==0)
                {
                    v[i]++;
                    v[i+k]+=-1;
                    cnt++;
                }
            }
            else
            {
                if(v[i]&1)
                {
                    v[i]++;
                    v[i+k]+=-1;
                    cnt++;
                }
            }
            nums[i]=1;
            //cout<<" i -> "<<i<<" cnt -> "<<cnt<<endl;
        }
        
        for(int i=n-k+1;i<n;i++)
        {
            v[i]+=v[i-1];
            
            if(nums[i]==0)
            {
                if(v[i]%2==0)
                return -1;
            }
            else
            {
                if(v[i]&1)
                return -1;
            }
        }
        
        return cnt;
    }
};