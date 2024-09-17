// Time complexity - O(N+N)
// Space complexity- O(N)
class Solution {
    public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        
        // for string 1
        string str="";
        for(int i=s1.length()-1;i>=0;i--)
        {
            if(s1[i]==' ')
            {
                mp[str]++;
                str="";
            }
            else
            str=s1[i]+str;
        }
        mp[str]++;
        str="";
        
        // for string 2
        for(int i=s2.length()-1;i>=0;i--)
        {
            if(s2[i]==' ')
            {
                mp[str]++;
                str="";
            }
            else
            str=s2[i]+str;
        }
        mp[str]++;
        
        vector<string> ans;
        for(auto& it:mp)
        {
            if(it.second==1)
            ans.push_back(it.first);
        }
        
        return ans;
    }
};
