// Attempt - 1
typedef pair<int,int> pi;
class Solution {
    public:
    void help(vector<pi>* adj,int node,int& n,int& distanceThreshold,vector<int>& dis)
    {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        dis[node]=0;
        pq.push({0,node});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            // if(d>distanceThreshold)
            // break;
            
            for(auto& it:adj[node])
            {
                int tempDistance=it.second+d;
                if(dis[it.first]>tempDistance)
                {
                    pq.push({tempDistance,it.first});
                    dis[it.first]=tempDistance;
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<pi> adj[n];
        for(auto& it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<pi> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> dis(n,1e9);
            help(adj,i,n,distanceThreshold,dis);
            
            int cnt=0;
            for(auto& it:dis)
            {
                if(it<=distanceThreshold)
                cnt++;
            }
            
            if(cnt!=0)
            ans.push_back({cnt,i});
        }
        
        sort(ans.begin(),ans.end(),[](pi& a,pi& b){
            if(a.first==b.first)
            return a.second>b.second;
            
            return a.first<b.first;
        });
            
        if(ans[0].first>distanceThreshold)
        return -1;
        
        return ans[0].second;
    }
};
