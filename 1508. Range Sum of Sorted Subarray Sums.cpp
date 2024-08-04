#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> sumArr;
        for(int i=0;i<n;i++)
        {
            ll sum=0;
            for(int j=i;j<n;j++)
            {
                sum=(sum%mod + nums[j]%mod)%mod;
                sumArr.push_back(sum);
            }
        }
        
        sort(sumArr.begin(),sumArr.end());
        
        int ans=0;
        for(int i=left-1;i<=right-1;i++)
        ans=(ans%mod + sumArr[i]%mod)%mod;
        
        return ans;
    }
};
