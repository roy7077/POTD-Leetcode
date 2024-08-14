// Time complexity - O((N^2)*LogN)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int s=0;
        int e=nums[n-1]-nums[0];
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            int cnt=0;
            int cntEqual=0;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(nums[j]-nums[i]==mid)
                    cntEqual++;
                    else if(nums[j]-nums[i]<mid)
                    cnt++;
                    
                    if(cnt>k)
                    break;
                }
                
                if(cnt>k)
                break;
            }
            
            if(cnt==k-1 and cntEqual)
            return mid;
            
            if(cnt<k and cnt+cntEqual>=k)
            return mid;
            
            if(cnt<k)
            s=mid+1;
            else
            e=mid-1;
        }
        return -1;
    }
};

// [1,1,3]
// 1

// 0 2 2


// [1,1,1]
// 2

// 0 0 0

// [4,62,100]
// 2
// 58 96 38
