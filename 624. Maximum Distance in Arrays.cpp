// Time complexity - O(2Log2)
// Space complexity- O(10)
typedef pair<int,int> pi;
class Solution {
    public:
    int maxDistance(vector<vector<int>>& arr) {
        
        priority_queue<pi,vector<pi>,greater<pi>> max_pq;
        priority_queue<pi> min_pq;
        
        for(int i=0;i<arr.size();i++)
        {
            // for min priority queue
            if(min_pq.size()<=1)
            min_pq.push({arr[i][0],i});
            else
            {
                if(min_pq.top().first>arr[i][0])
                {
                    min_pq.pop();
                    min_pq.push({arr[i][0],i});
                }
            }
            
            // for max priority queue
            if(max_pq.size()<=1)
            max_pq.push({arr[i][arr[i].size()-1],i});
            else
            {
                if(max_pq.top().first<arr[i][arr[i].size()-1])
                {
                    max_pq.pop();
                    max_pq.push({arr[i][arr[i].size()-1],i});
                }
            }
        }
        
        int ans=-1e9;
        pi mini2=min_pq.top();
        min_pq.pop();
        
        pi mini1=min_pq.top();
        min_pq.pop();
        
        pi maxi2=max_pq.top();
        max_pq.pop();
        
        pi maxi1=max_pq.top();
        max_pq.pop();
        
        if(mini1.second!=maxi1.second)
        return abs(maxi1.first-mini1.first);
                
        ans=max(ans,abs(maxi1.first-mini2.first));        
        ans=max(ans,abs(maxi2.first-mini1.first));        
        return ans;
    }
};
