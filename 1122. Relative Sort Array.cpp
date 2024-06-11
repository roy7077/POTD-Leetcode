// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        //storing element of array1 into map
        map<int,int> mp;
        for(auto& it:arr1)
        mp[it]++;
        
        //arranging in correct order
        int i=0;
        for(auto& it:arr2)
        {
            int size=mp[it];
            while(size--)
            {
                arr1[i]=it;
                i++;
            }
            mp.erase(it);
        }
        
        //for rest of the elements, that are not present in arr2
        for(auto& it:mp)
        {
            int size=it.second;
            while(size--)
            {
                arr1[i]=it.first;
                i++;
            }
            mp.erase(it.first);
        }
        
        return arr1;
    }
};