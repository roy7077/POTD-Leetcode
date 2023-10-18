class Solution {
    public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        
        //making adj list
        vector<int> adj[n+1];
        for(auto it:relations)
        {
            int a=it[0];
            int b=it[1];
            
            adj[a].push_back(b);
        }
        
        //indegree array
        vector<int> indegree(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(auto it:adj[i])
            indegree[it]++;
        }
        
        //topo sort
        vector<int> dis(n+1,0);
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dis[i]=time[i-1];
            }
        }

        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            
            for(auto it:adj[f])
            {
                int d=dis[f]+time[it-1];
                if(d>dis[it])
                dis[it]=d;
                
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        int ans=-1;
        dis[0]=-1;
        for(auto it:dis)
        ans=max(ans,it);
        
        return ans;
        
    }
};