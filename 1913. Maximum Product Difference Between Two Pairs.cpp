
/*-------------Method-1----------------*/
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        return ((nums[n-1]*nums[n-2])-(nums[0]*nums[1]));
    }
};

/*---------------Method-2---------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int maxProductDifference(vector<int>& nums) {
        int max1=-1e9;
        int max2=-1e9;
        
        for(auto it:nums)
        {
            if(it>max1)
            {
                max2=max1;
                max1=it;
            }
            else if(it==max1)
            max2=it;
            else if(it>max2)
            max2=it;
        }
        
        int min1=1e9;
        int min2=1e9;
        
        for(auto it:nums)
        {
            if(it<min1)
            {
                min2=min1;
                min1=it;
            }
            else if(it==min1)
            min2=it;
            else if(it<min2)
            min2=it;
        }
        
        return ((max1*max2)-(min1*min2));
    }
};