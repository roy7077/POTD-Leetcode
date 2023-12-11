// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int findSpecialInteger(vector<int>& arr) {
        
        int cnt=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            cnt++;
            else
            cnt=1;
            
            if(((25/100.0)*arr.size())<cnt)
            return arr[i];
        }
    
        if(((25/100.0)*arr.size())<cnt)
        return arr[arr.size()-1];
        
        return 0;
    }
};