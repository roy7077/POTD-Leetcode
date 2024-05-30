// Time complexity - O(N^3)
// Space complexity- O(N)
class Solution {
    public:
    int countTriplets(vector<int>& arr) {
        //prefix xor
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]^arr[i];
        
        //cnt number
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    if(i==0)
                    {
                        if((prefix[j])==(prefix[k]^prefix[j]))
                        cnt++;
                    }
                    else
                    {
                        if((prefix[j]^prefix[i-1])==(prefix[k]^prefix[j]))
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};