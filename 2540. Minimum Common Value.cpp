/* 
   Two pointer approach
   Time complexity - O(N+M)
   Space complexity- O(1)
*/
#define ll long long
class Solution {
    public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ll mini=1e18;
        int i=0;
        int j=0;
        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]>nums2[j])
            j++;
            else if(nums2[j]>nums1[i])
            i++;
            else
            {
                if(nums1[i]<mini)
                mini=nums1[i];
                i++;
                j++;
            }
        }
        return mini>=1e18 ? -1:mini;
    }
};

/* 
   Unordered map
   Time complexity - O(max(N,M))
   Space complexity- O(N)
*/
#define ll long long
class Solution {
    public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ll mini=1e18;
        unordered_map<int,int> mp;
        for(auto it:nums1)
        mp[it]++;
        
        for(auto it:nums2)
        {
            if(mp[it]>0)
            {
                if(it<mini)
                mini=it;
                
                mp[it]--;
            }
        }
        
        return mini>=1e18 ? -1:mini;
    }
};