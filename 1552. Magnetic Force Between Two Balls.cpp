// Binary Search
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=1;
        int e=1e9;
        int ans=-1;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            int cnt=1;
            int mini=1e9;
            int pre=0;
            for(int i=1;i<position.size();i++)
            {
                if((position[i]-position[pre])>=mid)
                {
                    mini=min(mini,(position[i]-position[pre]));
                    cnt++;   
                    pre=i;
                } 
                
                if(cnt>=m)
                break;
            }
            
            if(cnt>=m)
            {
                ans=max(ans,mini);
                s=mid+1;
            }
            else
            e=mid-1;
        }
        
        return ans;
    }
};