// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n=dist.size();
        for(int i=0;i<n;i++)
        dist[i]=((dist[i]-1)/speed[i]);
            
        
        sort(dist.begin(),dist.end());
        for(int i=0;i<n;i++)
        {
            if(i>dist[i])
            return i;
        }
        
        return n;
    }
};
