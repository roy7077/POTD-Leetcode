// Time complexity - O(NlogN)
// Space complexity- O(N)
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    
    ll reverse(ll n)
    {
        ll num=0;
        bool flag=1;
        while(n)
        {
            ll last=n%10;
            n/=10;
            
            if(last==0 and flag)
            continue;
            else
            {
                flag=0;
                num=num*10;
                num+=last;
            }
        }
        return num;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<ll,ll> mp;
        ll ans=0;
        for(auto& it:nums)
        {
            it=it-reverse(it);
            ans=(ans+mp[it])%mod;
            mp[it]++;
        }
        
        return ans;
    }
};