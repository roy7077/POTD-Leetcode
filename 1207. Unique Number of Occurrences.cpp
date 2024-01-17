// Method -1 (unordered map)
// Time complexity - O(N)
// Space complexity- O(2*N)
class Solution {
    public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp1,mp2;
        for(auto it:arr)
        mp1[it]++;
        
        for(auto it:mp1)
        {
            if(mp2.count(it.second))
            return 0;
            mp2[it.second]=1;
        }
        
        return 1;
    }
};


// Method -2 (sorting)
// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp1;
        sort(arr.begin(),arr.end());
        int cnt=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            cnt++;
            else
            {
                if(mp1.count(cnt))
                return 0;
                
                mp1[cnt]=1;
                cnt=1;
            }
        }
        
        if(mp1.count(cnt))
        return 0;
        
        return 1;
    }
};