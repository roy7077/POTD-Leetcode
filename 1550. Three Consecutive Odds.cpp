// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(i<=n-3)
        {
            if(arr[i]&1 and arr[i+1]&1 and arr[i+2]&1)
            return true;
            
            i++;
        }
        return false;
    }
};
