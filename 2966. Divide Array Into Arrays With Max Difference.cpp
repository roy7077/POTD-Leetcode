// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        int j=2;
        while(j<nums.size())
        {
            if((j+1)%3==0)
            {
               if((nums[j]-nums[i])>k)
                return {};
                else
                {
                    ans.push_back({nums[i],nums[i+1],nums[j]});
                    i+=3;
                }   
            }
            j+=3;
        }
        return ans;
    }
};