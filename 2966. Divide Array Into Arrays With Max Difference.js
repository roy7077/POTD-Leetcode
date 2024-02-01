// Time complexity - O(NlogN)
// Space complexity- O(N)
var divideArray = function(nums, k) {
    let ans=[];
    nums.sort();
    let i=0;
    let j=2;
    while(j<nums.length)
    {
        if((j+1)%3==0)
        {
            if((nums[j]-nums[i])>k)
            return [];
            else
            ans.push([nums[i],nums[i+1],nums[j]]);
        }
        i+=3;
        j+=3;
    }
    return ans;
};
