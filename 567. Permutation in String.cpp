class Solution {
    public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(auto& it:s1)
        mp[it]++;
        
        int j=0;
        int i=0;
        int prev=-1;
        unordered_map<char,int> mp2;
        int len=s2.length();
        while(j<len)
        {
            if(j!=prev and mp.count(s2[j]))
            {
                prev=j;
                mp2[s2[j]]++;
            }
            else if(mp.count(s2[j])==0)
            {
                mp2.clear();
                i=j+1;
                j++;
                continue;
            }
            
            int f=0;
            if(mp2.size()==mp.size())
            {
                bool flag=1;
                for(auto& it:mp)
                {
                    if(mp2.count(it.first)==0)
                    {
                        flag=0;
                        f=2;
                        break;
                    }
                    
                    if(mp2[it.first]>it.second)
                    {
                        if(mp.count(s2[i]))
                        {
                            mp2[s2[i]]--;
                            if(mp2[s2[i]]==0)
                            mp2.erase(s2[i]);
                            i++;
                            flag=0;
                            f=1;
                            break;
                        }
                    }
                    else if(mp2[it.first]<it.second)
                    {
                        flag=0;
                        f=2;
                        break;
                    }
                }
                
                if(flag)
                return 1;
            }
            
            if(f==2 or f==0)
            j++;
        }
        return 0;
    }
};
