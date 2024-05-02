/* 
  Unordered map
  Time complexity - O(N)
  Space complexity- O(N)
*/
class Solution {
    public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=-1;
        for(auto& it:nums)
        {
            if(mp.count(-1*it))
            {
                if(it>0)
                maxi=max(maxi,it);
                else
                maxi=max(maxi,-1*it);
            }
            
            mp[it]++;
        }
        return maxi;
    }
};