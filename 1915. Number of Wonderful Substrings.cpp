#define ll long long
class Solution {
    public:
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,int> mp;
        ll ans=0;
        ll xorr=0;
        mp[0]=1;
        
        for(auto& ch:word)
        {
            int curr_bin=1<<(ch-'a');
            xorr^=curr_bin;
            
            ans+=mp[xorr];
            
            for(char x='a';x<='j';x++)
            {
                curr_bin=1<<(x-'a');
                ll check_bin=xorr^curr_bin;
                
                ans+=mp[check_bin];
            }
            mp[xorr]++;
        }
        return ans;
    }
};