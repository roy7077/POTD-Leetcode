class Solution {
    public:
    bool binarySearch(vector<int>& nums,int x)
    {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ind=-1;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]>=x)
            {
                ind=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        
        if(ind==-1)
        return 0;
        
        return (n-ind)==x;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        int n=1000;
        while(n>=1)
        {
            int ind=binarySearch(nums,n);
            if(ind)
            return n;
            
            n--;
        }
        return -1;
    }
};
