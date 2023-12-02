// Time complexity - O(N*M)
// Space complexity- O(N+M)
class Solution {
    public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int> mp1;
        for(auto it:chars)
        mp1[it]++;
        
        int sum=0;
        for(auto it:words)
        {
            unordered_map<char,int> mp2;
            for(auto x:it)
            mp2[x]++;
            
            bool flag=1;
            for(auto x:mp2)
            {
                if(mp1[x.first]<x.second)
                {
                    flag=0;
                    break;
                }
            }
            
            if(flag)
            sum+=it.length();
        }
        return sum;
    }
};