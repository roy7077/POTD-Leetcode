/* Method - 1
   Unordered map
   Time complexity - O(N)
   Space complexity- O(26)
*/
class Solution {
    public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        
        s="";
        for(auto it:order)
        {
            int cnt=mp[it];
            while(cnt)
            {
                s+=it;
                cnt--;
            }
            mp[it]=0;
        }
        
        for(auto& it:mp)
        {
            while(it.second)
            {
                s+=it.first;
                it.second--;
            }
        }
        return s;
    }
};


/* Method - 2
   Unordered map and sorting
   Time complexity - O(NlogN)
   Space complexity- O(26)
*/
class Solution {
    public:
    unordered_map<char,int> mp;
    string customSortString(string order, string s) {
        for(int i=0;i<order.size();i++)
        mp[order[i]]=i+1;
        
        sort(s.begin(),s.end(),[this](char a,char b){
            if(mp.count(a)==0)
            return false;

            if(mp.count(b)==0)
            return true;

            return mp[a] < mp[b];
        });
        return s;
    }
};