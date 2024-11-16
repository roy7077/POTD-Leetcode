class Solution {
    public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0;
        int n=nums.size();
        while(i+k<=n)
        {
            bool flag=1;
            int j=i+1;
            int maxi=nums[i];
            while(j<(i+k))
            {
                if(nums[j]!=(nums[j-1]+1))
                {
                    flag=0;
                    break;
                }
                maxi=max(maxi,nums[j]);
                j++;
            }
            
            if(flag)
            ans.push_back(maxi);
            else
            ans.push_back(-1);
            
            i++;
        }
        return ans;
    }
};

// 0 1 2 3 4
