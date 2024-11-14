// Time complexity - O(NlogN)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    int minimizedMaximum(int n, vector<int>& q) {
        ll e=0;
        for(auto& it:q)
        e+=it;
        
        ll s=1;
        int mini=1e9;
        while(s<=e)
        {
            ll mid=(s+e)/2;
            ll cnt=0;
            ll j=0;
            while(j<q.size())
            {
                ll temp=ceil((double)q[j]/mid);
                cnt+=temp;
                
                j++;
            }
            
            if(cnt<=n)
            {
                if(mid<mini)
                mini=mid;
                
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return mini;
    }
};


// sum=35
// mid=17
