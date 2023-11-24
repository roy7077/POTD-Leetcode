// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    
    public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end(),greater<int>());
        int n=piles.size();
        int i=0;
        int j=n-1;
        
        int sum=0;
        while(i<j)
        {
            sum+=piles[i+1];
            i+=2;
            j--;
        }
        return sum;
    }
};
