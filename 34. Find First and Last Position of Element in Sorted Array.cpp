class Solution {
    public:
    
    // lower bound
    void left(vector<int>& nums,int l,int r,int target,int& ind1)
    {
        //base case
        if(l>r)
        return ;
        
        //recursive calls
        //small calculation
        
        int mid=(l+r)/2;
        if(nums[mid]==target)
        {
            cout<<mid<<endl;
            ind1=mid;
            return left(nums,l,mid-1,target,ind1);
        }
        else if(target>nums[mid])
        return left(nums,mid+1,r,target,ind1);
        else
        return left(nums,l,mid-1,target,ind1);
    }
    
    //upper bound
    void right(vector<int>& nums,int l,int r,int target,int& ind2)
    {
        //base case
        if(l>r)
        return ;
        
        //recursive calls
        //small calculation
        int mid=(l+r)/2;
        if(nums[mid]==target)
        {
            ind2=mid;
            return right(nums,mid+1,r,target,ind2);
        }
        else if(target>nums[mid])
        return right(nums,mid+1,r,target,ind2);
        else
        return right(nums,l,mid-1,target,ind2);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ind1,ind2;
        ind1=ind2=-1;
        left(nums,0,nums.size()-1,target,ind1);
        right(nums,0,nums.size()-1,target,ind2);
        
        if(ind1==-1)
        return {-1,-1};
        
        return {ind1,ind2};
    }
};