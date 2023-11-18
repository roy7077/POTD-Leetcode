/*--------------Brute force-----------*/
//Time complexity - O(N^2)
//Space complexity- O(1)
class Solution {
    public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            int j=i+1;
            int op=k;
            int cnt=1;
            while(j<n)
            {
                int req=nums[i]-nums[j];
                if(req<=op)
                {
                    op-=req;
                    cnt++;
                    j++;
                }
                else
                break;
            }
            i++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};

/*-------------Sum Approach---------*/
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int maxlen=0;
        int i=0;
        int j=0;
        
        while(j<nums.size())
        {
            sum+=nums[j];
            while(i<j)
            {
                if(long(long(nums[j])*(j-i+1))>sum+k)
                {
                    sum-=nums[i];
                    i++;
                }
                else
                break;
            }
            j++;
            maxlen=max(maxlen,j-i);
        }
        return maxlen;
    }
};