// Moore's Voting Algorithm
// c++
class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int num=-1;
        int cnt=0;
        
        for(auto it:nums)
        {
            if(it==num)
            cnt++;
            else if(cnt==0)
            {
                num=it;
                cnt=1;
            }
            else
            cnt--;
        }
        
        cnt=0;
        for(auto it:nums)
        {
            if(it==num)
            cnt++;
        }
        
        if(cnt>(n/3))
        return num;
        
        return -1;
    }
};
// JAVA
class Solution {
    public int majorityElement(int[] nums) {
        int ele=-1;
        int cnt=0;
        for(int i=0;i<nums.length;i++)
        {
            if(cnt==0)
            {
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele)
            cnt++;
            else
            cnt--;
        }

        cnt=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==ele)
            cnt++;
        }

        if(cnt>=(nums.length/2))
        return ele;

        return -1;
    }
}
// JAVASCRIPT
// Time complexity - O(N)
// Space complexity- O(1)
var majorityElement = function(nums) {
    let ele=-1;
    let cnt=0;
    
    for(let i=0;i<nums.length;i++)
    {
        if(cnt==0)
        {
            ele=nums[i];
            cnt=1;
        }
        else if(nums[i]==ele)
        cnt++;
        else
        cnt--;
    }
    
    cnt=0;
    for(let i=0;i<nums.length;i++)
    {
        if(nums[i]==ele)
        cnt++;
    }
    
    if(cnt>=(nums.length/2))
    return ele;
    
    return -1;
};