// Merge sort
// Time complexity - O(NlogN)
// Space complexity- O(logN)
class Solution {
    public:
    void mergeSort(vector<int>& nums,int s,int e)
    {
        vector<int> temp;
        int mid=(s+e)/2;
        int i=s;
        int j=mid+1;
        
        while(i<=mid and j<=e)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        
        while(j<=e)
        {
            temp.push_back(nums[j]);
            j++;
        }
        
        i=s;
        for(auto& it:temp)
        nums[i++]=it;
    }
    void merge(vector<int>& nums,int s,int e)
    {
        //base case
        if(s>=e)
        return ;
        
        //recursive calls
        //and small calculation
        int mid=(s+e)/2;
        merge(nums,s,mid);
        merge(nums,mid+1,e);
        mergeSort(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};
