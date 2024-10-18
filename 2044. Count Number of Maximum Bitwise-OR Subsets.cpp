// Time complexity - O(2^N)
// Space complexity- O(N)
class Solution {
    public:
    void help(vector<int>& nums,int i,int orr,int& maxOr,int& cnt)
    {
        // base case
        if(i>=nums.size())
        {
            if(orr>maxOr)
            {
                maxOr=orr;
                cnt=1;
            }
            else if(orr==maxOr)
            cnt++;
            return ;
        }
        
        // recursive calls
        // and small calculation
        help(nums,i+1,orr,maxOr,cnt);
        help(nums,i+1,orr|nums[i],maxOr,cnt);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        int cnt=0;
        help(nums,0,0,maxOr,cnt);
        
        return cnt;
    }
};
