/*
 Method - 1
 Recursion
 Time complexity - O(2^n)
*/
class Solution {
    public:
    void help(vector<int>& nums,int i,int& sum,int xorr)
    {
        //base case
        if(i>=nums.size())
        {
            sum+=xorr;
            return ;
        }
        
        //recursive calls
        //small calculation
        help(nums,i+1,sum,xorr);
        help(nums,i+1,sum,xorr^nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        help(nums,0,sum,0);
        return sum;
    }
};

/*
 Method - 2
 PowerSet
 Time complexity - O((2^N)*N)
*/
class Solution {
    public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<(1<<n);i++)
        {
            int xorr=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                xorr^=nums[j];
            }
            sum+=xorr;
        }
        return sum;
    }
};