/*-------Method-1--------*/
// Sorting and inserting 1e9
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        //finding duplicated
        vector<int> ans;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans.push_back(nums[i]);
                nums[i]=1e9;
                break;
            }
        }
        
        sort(nums.begin(),nums.end());
        
        //finding missing
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=(i+1))
            {
                ans.push_back(i+1);
                break;
            }
        }
        
        return ans;
    }
};



/*-------Method-2-----------*/
// sorting & sum 
// Time complexity - O(NlogN)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        ll sum1=0;
        ll sum2=0;
        
        int a=-1;
        int b=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i+1<nums.size() and nums[i]==nums[i+1])
            a=nums[i];
            
            sum1+=nums[i];
            sum2+=(i+1);
        }
        
        b=sum2-(sum1-a);
        return {a,b};
    }
};



/*-------Method-3-----------
best approach , make array as index */
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int a,b;
        
        //finding repeating number
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
            a=abs(nums[i]);
            else
            nums[abs(nums[i])-1]*=-1;
        }
        
        //finding missing number
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                b=i+1;
                break;
            }
        }
        
        return {a,b};
    }
};