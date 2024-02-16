/* Time complexity - O(NlogN)
   Space complexity- O(N)
   sorting and prefixsum
 */
#define ll long long
class Solution {
    public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<ll> prefix(n,0);
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+nums[i];
        
        ll len=-1;
        int ind=-1;
        for(int i=1;i<n;i++)
        {
            if(prefix[i-1]>nums[i])
            {
                len=i+1;
                ind=i;
            }
        }
        
        return ind<=1 ? -1:prefix[ind];
    }
};

// 1 1 2 3 5 12 50