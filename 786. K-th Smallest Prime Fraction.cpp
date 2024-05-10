// Time complexity - O(N^2)
// Space complexity- O(k)
typedef pair<double,pair<int,int>> pi;
class Solution {
    public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pi> pq;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                double fra=((double)arr[i])/arr[j];
                if(pq.size()<k)
                pq.push({fra,{arr[i],arr[j]}});
                else
                {
                    if(pq.top().first>fra)
                    {
                        pq.pop();
                        pq.push({fra,{arr[i],arr[j]}});
                    }
                }
            }
        }
    
        return {pq.top().second.first,pq.top().second.second};
    }
};