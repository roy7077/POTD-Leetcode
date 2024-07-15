class Solution {
    public:
    TreeNode* help(unordered_map<int,vector<vector<int>>>& adj,int node)
    {
        TreeNode* newNode=new TreeNode(node);
        for(auto& it:adj[node])
        {
            int child=it[0];
            int dir=it[1];
            
            if(dir)
            newNode->left=help(adj,child);
            else
            newNode->right=help(adj,child);
        }
        return newNode;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<vector<int>>> adj;
        unordered_map<int,int> indegree;
        for(auto& it:descriptions)
        {
            int parent=it[0];
            int child=it[1];
            int dir=it[2];
            
            indegree[child]++;
            adj[parent].push_back({child,dir});
        }
        
        int parent=-1;
        for(auto& it:descriptions)
        {
            if(indegree.count(it[0])==0)
            {
                parent=it[0];
                break;
            }
        }
        
        return help(adj,parent);
    }
};
