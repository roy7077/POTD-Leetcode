class Solution {
    public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double,int> mp;
        for(auto& it:arr)
        {
            if(mp.count(2*it) or mp.count(double(it/2.0)))
            return 1;
            
            mp[it]++;
        }
        return 0;
    }
};
