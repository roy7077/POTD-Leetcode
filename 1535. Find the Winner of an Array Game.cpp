// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int getWinner(vector<int>& arr, int k) {
        
        int cnt=0;
        int curr=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(curr>arr[i])
            cnt++;
            else
            {
                cnt=1;
                curr=arr[i];
            }
            
            if(cnt==k)
            return curr;
        }
        
        return curr;
    }
};