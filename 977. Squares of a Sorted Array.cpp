/* Method - 1
   Time complexity - O(NlogN)
   Space complexity- O(1)
*/
class Solution {
    public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& it:nums)
        it*=it;
        
        sort(nums.begin(),nums.end());
        return nums;
    }
};

/* Method - 2
   Time complexity - O(N)
   Space complexity- O(N)
*/
class Solution {
    public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& it:nums)
        it*=it;
        
        vector<int> ans(nums.size());
        int i=nums.size()-1;
        int l=0;
        int r=nums.size()-1;
        
        while(l<=r){
            if(nums[l]>nums[r]){
                ans[i]=nums[l];
                l++;
            }
            else{
                ans[i]=nums[r];
                r--;
            }
            i--;
        }
        return ans;
    }
};