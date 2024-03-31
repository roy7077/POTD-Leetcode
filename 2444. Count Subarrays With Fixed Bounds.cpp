// Sliding Window
// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll cnt=0;
        bool maxFound=0;
        bool minFound=0;
        int maxStart=0;
        int minStart=0;
        int start=0;
        
        for(int i=0;i<nums.size();i++)
        {
            // if current element is less than minK or greater then maxK
            // that's mean out of the range 
            if(nums[i]<minK or nums[i]>maxK)
            {
                maxFound=0;
                minFound=0;
                start=i+1;
            }
            
            if(nums[i]==minK)
            {
                minFound=1;
                minStart=i;
            }
            
            if(nums[i]==maxK)
            {
                maxFound=1;
                maxStart=i;
            }
            
            if(minFound and maxFound)
            cnt+=(min(maxStart,minStart)-start+1);
            /*
              [   ] ranged elements
                    [min and max] 
                                  newElement
              count of subarrays for newElement will be the size of ranged element
            */
        }
        return cnt;
    }
};