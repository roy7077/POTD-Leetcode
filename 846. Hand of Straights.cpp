class Solution {
    public:
    bool isNStraightHand(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto& it:nums)
        mp[it]++;
        
        while(mp.size())
        {
            int pre=-1;
            int cnt=0;
            auto it = mp.begin();
            while(it!=mp.end())
            {
                if(pre==-1)
                {
                    pre=it->first;
                    it->second=it->second-1;
                }
                else
                {
                    if((it->first)!=(pre+1))
                    return 0;
                    
                    it->second=it->second-1;
                }
                
                pre=it->first;
                
                if(it->second<=0)
                it=mp.erase(it);
                else
                it++;
                
                cnt++;
                
                if(cnt>=k)
                break;
            }
            
            if(cnt<k)
            return 0;
        }
        return 1;
    }
};