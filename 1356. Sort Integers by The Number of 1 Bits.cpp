class Solution {
    public:
    static bool cmp(int a,int b)
    {
        int n= __builtin_popcount(a);
        int m= __builtin_popcount(b);
        
        if(n==m)
        return a<b;
        
        if(n<m)
        return 1;
        else
        return 0;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};