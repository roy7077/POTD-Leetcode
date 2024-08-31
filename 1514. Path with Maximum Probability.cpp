typedef pair<double,int> pi;
typedef pair<int,double> pii;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        // make an adj list
        vector<pii> adj[n];
        for(int i=0;i<edges.size();i++)
        {
           int node1=edges[i][0];
           int node2=edges[i][1];
           adj[node1].push_back({node2,succProb[i]});
           adj[node2].push_back({node1,succProb[i]});
        }
        
        // go for dijkstra algorithm
        vector<double> dis(n,-1);
        priority_queue<pi> pq;
        dis[start_node]=1;
        
        pq.push({1,start_node});
        
        while(!pq.empty())
        {
           auto it=pq.top();
           pq.pop();
           
           int node=it.second;
           double pro=it.first;
           
           for(auto& child:adj[node])
           {
              if(dis[child.first]<(pro*child.second))
              {
                 dis[child.first]=pro*child.second;
                 pq.push({dis[child.first],child.first});
              }
           }
        }
        
        return dis[end_node] > 0 ? dis[end_node] : double(0);
    }
};


// queue= {0,0}

// dis [0,0,0]
