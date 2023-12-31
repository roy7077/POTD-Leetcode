// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int maxi=-1;
        for(int i=0;i<s.length();i++)
        {
            char it=s[i];
            if(mp.count(it))
            maxi=max(maxi,((i+1)-(mp[it]))-2);
            else
            mp[it]=i;
        }
        return maxi;
    }
};