// Time complexity - O(N)
// Space complexity- O(26+26)
typedef pair<int,char> pic;
class Solution {
    public:
    int minimumPushes(string word) {
        
        // store the frequency of each characters
        // Time complexity - O(N)
        unordered_map<char,int> mp;
        for(auto& it:word)
        mp[it]++;
        
        // store in array and sort
        // Time complexity - O(26*log26)
        vector<pic> v;
        for(auto& it:mp)
        v.push_back({it.second,it.first});
        
        sort(v.begin(),v.end(),greater<pic>());
        
        // calculate ans
        // Time complexity - O(26)
        int cntPress=0;
        int i=0;
        int cnt=0;
        while(i<v.size())
        {
            if(i%8==0)
            cnt++;
            
            cntPress+=cnt*v[i].first;
            i++;
        }
        
        return cntPress;
    }
};
