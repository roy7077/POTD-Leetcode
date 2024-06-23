// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mp;
        int ans=0;
        int i=0;
        int j=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            int maxi=prev(mp.end())->first;
            int mini=mp.begin()->first;
            
            if((maxi-mini)<=limit)
            ans=max(ans,j-i+1);
            else
            {
                int ele=nums[i];
                mp[ele]--;
                
                if(mp[ele]==0)
                mp.erase(ele);
                i++;
            }
            j++;
        }
        return ans;
    }
};