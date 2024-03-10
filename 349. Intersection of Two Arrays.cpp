/* Method - 1
   Unordered_map 
   Time complexity - O(N)
   Space complexity- O(26)
*/
class Solution {
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto it:nums1)
        mp[it]++;
        
        vector<int> ans;
        for(auto it:nums2)
        {
            if(mp[it]>=1)
            {
                ans.push_back(it);
                mp[it]=0;
            }
        }
        return ans;
    }
};


/* Method - 2
   Two pointers 
   Time complexity - O(NlogN)
   Space complexity- O(1)
*/
class Solution {
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> ans;
        int i=0;
        int j=0;
        
        while(i<nums1.size() and j<nums2.size())
        {
            while(i+1<nums1.size() and nums1[i]==nums1[i+1])
            i++;
            
            while(j+1<nums2.size() and nums2[j]==nums2[j+1])
            j++;
            
            if(nums1[i]>nums2[j])
            j++;
            else if(nums2[j]>nums1[i])
            i++;
            else
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};