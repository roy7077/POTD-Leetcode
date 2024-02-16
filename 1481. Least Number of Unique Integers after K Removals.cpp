/* Unordered map , pair and sorting
   Time complexity - O(N)
   Space complexity- O(2*N)
*/
typedef pair<int,int> pi;
class Solution {
    public:
    bool cmp(pi& a,pi& b)
    {
        return a.first<b.first;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it:arr)
        mp[it]++;
        
        vector<pi> v;
        for(auto it:mp)
        v.push_back({it.second,it.first});
        
        sort(v.begin(),v.end());
        int cnt=0;
        for(auto it:v)
        {
            if(it.first<=k)
            {
                cnt++;
                k-=it.first;
            }
            else
            break;
        }
        
        return v.size()-cnt;
    }
};